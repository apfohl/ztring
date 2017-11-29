# Ztring

[![Build Status](https://travis-ci.org/apfohl/ztring.svg?branch=master)](https://travis-ci.org/apfohl/ztring)
[![Coverage Status](https://coveralls.io/repos/github/apfohl/ztring/badge.svg?branch=master)](https://coveralls.io/github/apfohl/ztring?branch=master)

Ztring is a dynamic string library for C.

## Installation

### macOS with Homebrew

If you use Homebrew under macOS you can use the tap `apfohl/brew`:

    $ brew tap apfohl/brew
    $ brew install ztring

### Manually

Ztring comes as a static linkable library. In order to use it, you need to compile it first.

To build a release version you need to run the following command

    $ make release

To make the library available for use, you have to install it to the right location. You can set the `PREFIX` environment variable to set the installation path. The default is `/usr/local`. The installation is done by the following command:

    $ make install

or, if you want to change the `PREFIX`:

    $ make install PREFIX=/your/prefix

Of cause you can uninstall it with the following command:

    $ make uninstall

## Usage

To use Ztring in your projects, you need to link against the library. If you have installed the library to the default `PREFIX` or with Homebrew, you can simply use the `-lztring` flag for compilation.

Example:

    $ clang -o app app.c -lztring

## API

Coming soon...
