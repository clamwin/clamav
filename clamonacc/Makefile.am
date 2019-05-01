#
#  Copyright (C) 2018 Cisco Systems, Inc. and/or its affiliates. All rights reserved.
#
#  Authors: Mickey Sola
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.

if BUILD_CLAMD

bin_PROGRAMS = clamonacc

clamonacc_CPPFLAGS="-g"
clamonacc_CFLAGS="-g"

clamonacc_SOURCES = \
    $(top_srcdir)/shared/output.c \
    $(top_srcdir)/shared/output.h \
    $(top_srcdir)/shared/optparser.c \
    $(top_srcdir)/shared/optparser.h \
    $(top_srcdir)/shared/misc.c \
    $(top_srcdir)/shared/misc.h \
    $(top_srcdir)/shared/getopt.c \
    $(top_srcdir)/shared/getopt.h \
    $(top_srcdir)/shared/actions.c \
    $(top_srcdir)/shared/actions.h \
    $(top_srcdir)/shared/priv-fts.h \
    clamonacc.c \
    ./client/onaccess_client.c \
    ./client/onaccess_client.h \
    ./client/onaccess_proto.c \
    ./client/onaccess_proto.h \
    ./client/onaccess_com.c \
    ./client/onaccess_com.h \
    ./inotif/onaccess_ddd.c \
    ./inotif/onaccess_ddd.h \
    ./fanotif/onaccess_fan.c \
    ./fanotif/onaccess_fan.h \
    ./inotif/onaccess_hash.c \
    ./inotif/onaccess_hash.h \
    ./misc/onaccess_others.c \
    ./misc/onaccess_others.h \
    ./misc/priv_fts.h \
    ./scan/onaccess_scth.c \
    ./scan/onaccess_scth.h

if !SYSTEM_LFS_FTS
clamonacc_SOURCES += ./misc/fts.c
endif

AM_CFLAGS=@WERR_CFLAGS@
endif

DEFS = @DEFS@ -DCL_NOLIBCLAMAV
LIBS = $(top_builddir)/libclamav/libclamav_internal_utils.la @CURL_LDFLAGS@ @CURL_LIBS@ @CLAMONACC_LIBS@ @THREAD_LIBS@
AM_CPPFLAGS = -I$(top_srcdir) -I$(top_srcdir)/clamd -I$(top_srcdir)/shared -I$(top_srcdir)/libclamav @CURL_CPPFLAGS@ @SSL_CPPFLAGS@ @CLAMONACC_CPPFLAGS@ @JSON_CPPFLAGS@ @PCRE_CPPFLAGS@

AM_INSTALLCHECK_STD_OPTIONS_EXEMPT=clamonacc$(EXEEXT)
CLEANFILES=*.gcda *.gcno