mkdir model_files
cd model_files
wget -O ./MobileNetSSD_deploy.caffemodel "https://www.dropbox.com/s/w531w3qhfknr0dl/MobileNetSSD_deploy.caffemodel?dl=1"
wget -O ./MobileNetSSD_deploy.prototxt "https://www.dropbox.com/s/fn9rh3mdpu0u613/MobileNetSSD_deploy.prototxt?dl=1"
cd ..
#Download Testing Data
cd test
wget -O ./Images.zip "https://www.dropbox.com/s/927qcc6erk1h4ln/Images.zip?dl=1"
sudo apt-get install unzip
unzip Images.zip
wget -O ./test_annotation.json "https://www.dropbox.com/s/52ob56vr9eqg8fw/test_annotation.json?dl=1"