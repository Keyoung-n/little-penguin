make
insmod main.ko
cat /dev/fortywo
echo "Testing write: with bad output";
echo "lol" > /dev/fortytwo
echo "Testing write: with good output"
echo "knage" > /dev/fortytwo_dir
echo "testing read"
cat /dev/fortytwo
rmmod main.ko
