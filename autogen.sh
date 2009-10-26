#!/bin/sh

autoheader
aclocal -I m4
autoheader
autoconf
automake

