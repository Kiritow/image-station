#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

#include <string>
#include <vector>
using namespace std;

// launcher [-ezkn] [-p PoolSize] [-f TokenFilename] ServerIP ServerPort ProxyName ProxyType LocalPort RemotePort
int main(int argc, char *argv[])
{
    int ch = 0;
    int noExec = 0;
    int enableCompression = 0;
    int enableEncryption = 0;
    int enableKCP = 0;
    int poolSize = 0;
    const char *serverIP = NULL;
    int serverPort = 0;
    const char *proxyName = NULL;
    const char *proxyType = NULL;
    int localPort = 0;
    int remotePort = 0;
    int enableToken = 0;
    char token[256] = {0};
    vector<pair<string, string>> metaVec;

    while ((ch = getopt(argc, argv, "ezknm:p:f:")) != -1)
    {
        switch (ch)
        {
        case 'e':
            enableEncryption = 1;
            break;
        case 'z':
            enableCompression = 1;
            break;
        case 'k':
            enableKCP = 1;
            break;
        case 'm':
            {
                char* p = strtok(optarg, "=");
                if(p)
                {
                    metaVec.emplace_back(string(optarg, p - optarg), string(p+1));
                }
                break;
            }
        case 'p':
            if (sscanf(optarg, "%d", &poolSize) < 1)
            {
                fprintf(stderr, "Cannot parse pool size.\n");
                exit(2);
            }
            break;
        case 'f':
        {
            FILE *fp = fopen(optarg, "r");
            if(!fp)
            {
                perror("fopen");
                exit(2);
            }
            if (fscanf(fp, "%s", token) < 1) {
                fprintf(stderr, "Cannot read token.\n");
                exit(2);
            }
            fclose(fp);
            enableToken = 1;
            break;
        }
        case 'n':
            noExec = 1;
            break;
        case '?':
            exit(2);
        }
    }

    if (optind + 6 > argc)
    {
        fprintf(stderr, "not enough arguments, 6 needed, got %d\n", argc - optind);
        exit(2);
    }

    serverIP = argv[optind];
    if (sscanf(argv[optind + 1], "%d", &serverPort) < 1)
    {
        fprintf(stderr, "Cannot parse server port.\n");
        exit(2);
    }
    proxyName = argv[optind + 2];
    proxyType = argv[optind + 3];
    if (sscanf(argv[optind + 4], "%d", &localPort) < 1)
    {
        fprintf(stderr, "Cannot parse local port.\n");
        exit(2);
    }
    if (sscanf(argv[optind + 5], "%d", &remotePort) < 1)
    {
        fprintf(stderr, "Cannot parse remote port.\n");
        exit(2);
    }

    char hname[256] = {0};
    if (gethostname(hname, sizeof(hname)) < 0) {
        fprintf(stderr, "Unable to get hostname.\n");
        exit(2);
    }

    FILE *fp = fopen("frpc.ini", "w");
    if(!fp)
    {
        perror("fopen");
        exit(2);
    }
    fprintf(fp, "[common]\nserver_addr = %s\nserver_port = %d\n", serverIP, serverPort);
    if (enableToken)
    {
        fprintf(fp, "token = %s\n", token);
    }
    if (enableKCP)
    {
        fprintf(fp, "protocol = kcp\n");
    }
    if (poolSize > 0)
    {
        fprintf(fp, "pool_count = %d\n", poolSize);
    }

    fprintf(fp, "\n[%s-%s]\ntype = %s\nlocal_ip = 127.0.0.1\nlocal_port = %d\nremote_port = %d\n", proxyName, hname, proxyType, localPort, remotePort);
    if (enableEncryption)
    {
        fprintf(fp, "use_encryption=true\n");
    }
    if (enableCompression)
    {
        fprintf(fp, "use_compression=true\n");
    }

    for(auto& pr : metaVec)
    {
        fprintf(fp, "meta_%s = %s\n", pr.first.c_str(), pr.second.c_str());
    }

    fclose(fp);

    if (!noExec)
    {
        fprintf(stderr, "Loading frpc...\n");
        const char* callArgs[] = {"frpc", "-c", "frpc.ini", NULL};
        if (execv("/frpc", (char* const*)callArgs) < 0)
        {
            perror("execv");
        }
    }

    return 0;
}
