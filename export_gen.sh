# TODO: add hints/ordinals into these exports aswell

grep "Function Name" $1 |
awk '{print $4}' |
while read h; do
	echo "#pragma comment(linker, \"/export:$h=$2.$h\")"
done > exports.h
