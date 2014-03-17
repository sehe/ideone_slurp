slurp.exe:
	mcs *.cs -r:System.Web.Services -out:$@
