#! /bin/bash

if ! [[ -d ../../xv6-public ]]; then
    echo "Your xv6 code shouldn't be found "
    echo "along with ostep-projects directory."
    exit 1
fi

(rm -rf ./src | true) && cp -r ../../xv6-public ./src

if ! [[ -d src ]]; then
    echo "The src/ dir does not exist."
    echo "Your xv6 code should be in the src/ directory"
    echo "to enable the automatic tester to work."
    exit 1
fi

../tester/run-tests.sh $*


