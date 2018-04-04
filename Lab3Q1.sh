echo "Enter a file name"
read l
if [ -d "$l" ]; then
	echo "directory"
elif [ -f "$l" ]; then
	echo "file"
else
	echo "others"
fi
