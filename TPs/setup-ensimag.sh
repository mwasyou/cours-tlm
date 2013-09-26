#! /bin/echo Non, il ne faut pas executer ce fichier, mais faire: source

export SYSTEMCROOT=~moy/tlm/systemc-2.3.0/

# Chaine de cross-compilation MicroBlaze, pour le TP3
xilinx=~moy/tlm/microblaze/setup.sh
if [ -f "$xilinx" ]; then
    source "$xilinx"
fi
