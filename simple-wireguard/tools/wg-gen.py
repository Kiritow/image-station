# -*- coding: utf-8 -*-
import sys
import subprocess


if __name__ == "__main__":
    prik = subprocess.check_output(["wg", "genkey"])
    print("[PrivateKey]: {}".format(prik.strip()))
    subp = subprocess.Popen(["wg", "pubkey"], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    pubk = subp.communicate(input=prik)[0]
    print("[Public Key]: {}".format(pubk.strip()))
    subp.wait()
