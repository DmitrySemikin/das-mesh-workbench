#!/bin/bash

# This script is supposed to be run by Github Actions
# as part of continuous integration.

# It is supposed to be run on clean ubuntu 20.04
# (but probably it will also work for other versions or even
# other operation systems).

## This script is being run from the repo, so we assume, that
## the repo is already cloned, i.e. the commands below were already
## run.
# sudo apt-get -y install git
# git clone https://github.com/DmitrySemikin/vtk-mirror.git

# For Actions we don't need to install git (and I guess also cmake).
# And cloning is done using action

scriptDir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
srcDir="$( cd ${scriptDir}/.. >/dev/null 2>&1 && pwd )"
workingDir="$( cd "${srcDir}/.." >/dev/null 2>&1 && pwd )"
buildDirName="dasmw-build"
buildDir="${workingDir}/${buildDirName}"
installDirName="dasmw-install"
installDir="${workingDir}/${installDirName}"
vtkArchiveFileName="daswb-depends_vtk-9.0.1_ubuntu-20.04.tar.gz"
vtkArchiveFile="${workingDir}/${vtkArchiveFileName}"
vtkInstallDirName="daswb-depends_vtk-9.0.1_ubuntu-20.04"
vtkInstallDir="${workingDir}/${vtkInstallDirName}"

startTime=$(date +%s)


installStartTime=$(date +%s)

sudo apt-get update \
&& sudo apt-get -y install \
    git \
    wget \
    g++ \
    cmake \
    ninja-build \
    qtbase5-dev

rc=$?

installEndTime=$(date +%s)
echo "Installation of packages is complete in $((${installEndTime} - ${installStartTime})) seconds."

if [[ ${rc} != 0 ]]; then
    echo "ERROR: Failed to install packages." >&2
    exit 1
fi



downloadStartTime=$(date +%s)

cd "${workingDir}" \
&& wget "https://github.com/DmitrySemikin/vtk-mirror/releases/download/dasmw-depends_vtk-9.0.1/daswb-depends_vtk-9.0.1_ubuntu-20.04.tar.gz"
rc=$?

downloadEndTime=$(date +%s)
echo "Download of VTK binaries is complete in $((${downloadEndTime} - ${downloadStartTime})) seconds."

if [[ ${rc} != 0 ]]; then
    echo "ERROR: Failed to download vtk binaries." >&2
    exit 1
fi



unpackVtkStartTime=$(date +%s)

cd "${workingDir}" \
&& tar --extract --gzip --file "${vtkArchiveFileName}"
rc=$?

unpackVtkEndTime=$(date +%s)
echo "Unpacking of vtk binaries is complete it $((${unpackVtkEndTime} - ${unpackVtkStartTime})) seconds"

if [[ ${rc} != 0 ]]; then
    echo "ERROR: Failed to unpack VTK binaries archive." >&2
    exit 1
fi



buildStartTime=$(date +%s)

mkdir -p "${buildDir}"
rc=$?
if [[ ${rc} != 0 ]]; then
    echo "ERROR: Failed to create build dir." >&2
    exit 1
fi

cmake \
    -G Ninja \
    -DCMAKE_VERBOSE_MAKEFILE=ON \
    -DCMAKE_INSTALL_PREFIX="${installDir}" \
    -DCMAKE_PREFIX_PATH="${vtkInstallDir}" \
    -DCMAKE_BUILD_TYPE="Debug" \
    -S "${srcDir}" \
    -B "${buildDir}"
rc=$?

if [[ ${rc} != 0 ]]; then
    echo "ERROR: cmake (generate) invocation failed." >&2
    echo "Return code: ${rc}" >&2
    exit 1
fi

cmake --build "${buildDir}"
rc=$?
if [[ ${rc} != 0 ]]; then
    echo "ERROR: Build failed." >&2
    echo "Return code: ${rc}" >&2
    exit 1
fi


buildEndTime=$(date +%s)
echo "Build is complete in $((${buildEndTime} - ${buildStartTime})) seconds."


endTime=$(date +%s)
echo "Build is complete in $((${endTime} - ${startTime})) seconds."
