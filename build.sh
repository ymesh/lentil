#!/bin/bash -e
# 
# Build lentil & CryptomatteArnold plugins
# 
app_name=lentil
app_dir=${app_name}
app_ver=2.5.1

cryptomatte_ver=1.2.3
ARNOLD_VERSION=7.2.5.0

libs_dir=/home/data/tools
deploy_dir=${libs_dir}/${app_dir}/${app_name}-v${app_ver}-linux-${ARNOLD_VERSION}
export ARNOLD_ROOT=/opt/solidangle/Arnold-${ARNOLD_VERSION}-linux

build_dir=build
mkdir -p ${build_dir}
pushd ${build_dir}

echo "*"
echo "* building ${app_name} v${app_ver} for Arnold ${ARNOLD_VERSION}..."
echo "*"

tmp_dir=tmp_${app_name}-v${app_ver}-${ARNOLD_VERSION}
mkdir -p ${tmp_dir}
pushd ${tmp_dir}

cmake -L -G "Unix Makefiles" \
-DCMAKE_BUILD_TYPE="Release" \
-DINSTALL_DIR=${deploy_dir} \
-DCMAKE_POLICY_DEFAULT_CMP0074=NEW \
../../pota

if [ $? -eq 0 ]
then
  popd
  make -C ${tmp_dir} install
else
  echo "* cmake config error!"
  popd
fi

echo "*"
echo "* building cryptomatte v${cryptomatte_ver} for Arnold ${ARNOLD_VERSION}..."
echo "*"

tmp_dir=tmp_cryptomatte-v${cryptomatte_ver}-${ARNOLD_VERSION}
mkdir -p ${tmp_dir}
pushd ${tmp_dir}

cmake -L -G "Unix Makefiles" \
-DCMAKE_BUILD_TYPE="Release" \
-DINSTALL_DIR=${deploy_dir} \
-DCMAKE_POLICY_DEFAULT_CMP0074=NEW \
../../CryptomatteArnold

if [ $? -eq 0 ]
then
  popd
  make -C ${tmp_dir} install
else
  echo "* cmake config error!"
  popd
fi
popd

