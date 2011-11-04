#! /bin/echo Non, il ne faut pas executer ce fichier, mais faire: source

export SYSTEMCROOT=~moy/tlm/systemc-2.2.0/
export TLMOSCI=~moy/tlm/TLM-2009-07-15/
export TLM_ENSITLM=~moy/tlm/ensitlm
export SC_SIGNAL_WRITE_CHECK=DISABLE

# Chaine de cross-compilation MicroBlaze, pour le TP3
# En théorie, on peut utiliser l'une ou l'autre, au choix. Mais en
# pratique, la chaine Xilinx ne marche pas (il y a une boucle infinie,
# on ne joue jamais l'itération 2 du jeu de la vie !)
petalinux=/home/perms/moy/petalinux-v0.40-final/settings-moy.sh
if [ -f "$petalinux" ]; then
    source "$petalinux"
fi

# xilinx=/home/perms/moy/microblaze_v1.0/setup.sh
# if [ -f "$xilinx" ]; then
#     source "$xilinx"
# fi
