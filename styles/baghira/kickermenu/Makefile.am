INCLUDES = $(all_includes)

kde_module_LTLIBRARIES = b_menu_panelapplet.la

b_menu_panelapplet_la_SOURCES = menuapplet.cpp menuapplet.skel

noinst_HEADERS = menuapplet.h

b_menu_panelapplet_la_METASOURCES = AUTO

b_menu_panelapplet_la_LDFLAGS = -module $(KDE_PLUGIN) $(all_libraries)
b_menu_panelapplet_la_LIBADD = $(LIB_KDEUI)

messages:
	$(XGETTEXT) *.cpp *.h -o $(podir)/kmenuapplet.pot
