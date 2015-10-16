import qbs 1.0

StaticLibrary {
    name: "CppConcurrencyInAction_Lib"
    files: ["*.cpp", "*.h"]

	cpp.cxxLanguageVersion: "c++14"
	cpp.includePaths: [
		"../Src/",
		"../Ext/ValpineBase/Src"
	]

    Depends { name: "cpp" }
}
