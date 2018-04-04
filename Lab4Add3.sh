echo "Enter file name"
read f
echo "Enter line numbers range"
read s n
sed -n $s,$n\p $f | cat > newline
cat newline
