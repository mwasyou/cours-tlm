#! /bin/echo Non, il ne faut pas executer ce fichier, mais faire: source

export SYSTEMCROOT=~moy/tlm/systemc-2.3.0/

# Chaine de cross-compilation MicroBlaze, pour le TP3
# En théorie, on peut utiliser l'une ou l'autre, au choix.
xilinx=~moy/microblaze_v1.0/setup.sh
if [ -f "$xilinx" ]; then
    source "$xilinx"
fi

# petalinux=/home/perms/moy/petalinux-v0.40-final/settings-moy.sh
# if [ -f "$petalinux" ]; then
#     source "$petalinux"
# fi

