```
git clone --recursive https://github.com/sifive/freedom-e-sdk.git

cd freedom-e-sdk

make tools

make software

cd software

git clone git@github.com:satoshilabs/signtest.git

cd ..

make software PROGRAM=signtest

make upload PROGRAM=signtest
```
