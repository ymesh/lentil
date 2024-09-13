@echo OFF
rem 
rem Build lentil & CryptomatteArnold plugins
rem 
set app_name=lentil
set app_dir=%app_name%
set app_ver=2.5.1

set cryptomatte_ver=1.2.3
set ARNOLD_VERSION=7.3.3.1

set libs_dir=D:/data/libs
set deploy_dir=%libs_dir%/%app_dir%/%app_name%-v%app_ver%-windows-%ARNOLD_VERSION%
set ARNOLD_ROOT=%libs_dir%/Autodesk/Arnold-%ARNOLD_VERSION%

rem call D:/data/code/plarium/venv310/Scripts/activate.bat

set build_dir=build
if not exist %build_dir% mkdir %build_dir%
pushd %build_dir%
echo *
echo * building %app_name% v%app_ver% for Arnold %ARNOLD_VERSION% ...
echo *
set tmp_dir=tmp_%app_name%-v%app_ver%-%ARNOLD_VERSION%
if not exist %tmp_dir% mkdir %tmp_dir%
pushd %tmp_dir%

cmake -L -G "NMake Makefiles" ^
-DCMAKE_BUILD_TYPE="Release" ^
-DINSTALL_DIR="%deploy_dir%" ^
-DCMAKE_POLICY_DEFAULT_CMP0074=NEW ^
../../pota

if %ERRORLEVEL% == 0 (
  nmake install
  popd
) else (
  echo * cmake config error!
  popd
)
echo *
echo * building cryptomatte v%cryptomatte_ver% for Arnold %ARNOLD_VERSION% ...
echo *
set tmp_dir=tmp_cryptomatte-v%cryptomatte_ver%-%ARNOLD_VERSION%
if not exist %tmp_dir% mkdir %tmp_dir%
pushd %tmp_dir%

cmake -L -G "NMake Makefiles" ^
-DCMAKE_BUILD_TYPE="Release" ^
-DINSTALL_DIR="%deploy_dir%" ^
-DCMAKE_POLICY_DEFAULT_CMP0074=NEW ^
../../CryptomatteArnold

if %ERRORLEVEL% == 0 (
  nmake install
  popd
) else (
  echo * cmake config error!
  popd
)

popd

