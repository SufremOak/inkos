INPUT_DIR=./images
OUTFILENAME="system_images.tar"
ZIPPER=tar

sudo mkdir -p /tmp/inkos/imgs
sudo cp $INPUT_DIR/*.jpg /tmp/inkos/imags/
sudo mv /tmp/inkos/imags/donotdisconnect.jpg /tmp/inkos/imags/sync.jpg

if command -v "$ZIPPER" &> /dev/null; then
    $ZIPPER ../../out/$OUTFILENAME /tmp/inkos/imags/*.jpg
else
    echo "cannot find bsdtar!"
    exit 1
fi