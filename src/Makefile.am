bin_PROGRAMS=tgalaxy

tgalaxy_SOURCES = main.cpp \
				  gameobj.cpp \
				  entitymanager.cpp \
				  dispatcher.cpp \
				  projectile.cpp \
				  defender.cpp \
				  alien.cpp \
				  world.cpp \
				  alienstates.cpp \
				  game.cpp \
				  printer.cpp \
				  star.cpp

tgalaxy_LDADD = @GLUT_LIBS@

INCLUDES = -I@top_srcdir@/src/include

EXTRA_DIST = include Makefile.win

distclean-local:
	-rm -rf .deps

