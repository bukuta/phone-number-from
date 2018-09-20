cget install pfultz2/cget-recipes
cget install nlohmann/json
cget install Microsoft/cpprestsdk
echo "https://gitlab.com/bzip/bzip2/-/archive/master/bzip2-master.tar.gz -X build.cmake " > cget/etc/gzip2/package.txt
cget install boost

git clone https://github.com/ReactiveX/RxCpp --recurse-submodules


