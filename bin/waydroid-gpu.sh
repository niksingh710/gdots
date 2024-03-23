#!/bin/bash

lspci="$(lspci -nn | grep '\[03')" # https://pci-ids.ucw.cz/read/PD/03

echo -e "Please enter the GPU number you want to pass to WayDroid:\n"
gpus=()
i=0
while IFS= read lspci; do
	gpus+=("$lspci")
	echo "  $((++i)). $lspci"
done < <(echo "$lspci")
echo ""
while [ -z "$gpuchoice" ]; do
	read -erp ">> Number of GPU to pass to WayDroid (1-${#gpus[@]}): " ans
	if [[ "$ans" =~ [0-9]+ && $ans -ge 1 && $ans -le ${#gpus[@]} ]]; then
		gpuchoice="${gpus[$((ans-1))]%% *}" # e.g. "26:00.0"
	fi
done

echo ""
echo "Confirm that these belong to your GPU:"
echo ""

ls -l /dev/dri/by-path/ | grep -i $gpuchoice

echo ""

card=$(ls -l /dev/dri/by-path/ | grep -i $gpuchoice | grep -o "card[0-9]")
rendernode=$(ls -l /dev/dri/by-path/ | grep -i $gpuchoice | grep -o "renderD[1-9][1-9][1-9]")

echo /dev/dri/$card
echo /dev/dri/$rendernode

cp /var/lib/waydroid/lxc/waydroid/config_nodes /var/lib/waydroid/lxc/waydroid/config_nodes.bak
#lxc.mount.entry = /dev/dri dev/dri none bind,create=dir,optional 0 0
sed -i '/dri/d' /var/lib/waydroid/lxc/waydroid/config_nodes
echo "lxc.mount.entry = /dev/dri/$rendernode dev/dri/renderD128 none bind,create=file,optional 0 0" >> /var/lib/waydroid/lxc/waydroid/config_nodes
