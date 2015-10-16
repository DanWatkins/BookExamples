import qbs 1.0

Application {
    name: "CppConcurrencyInAction_Tests"
    files: ["*.cpp", "*.h"]

	cpp.cxxLanguageVersion: "c++14"
	cpp.includePaths: [
		"../Src/",
		"../Ext/ValpineBase/Src"
	]

    Depends { name: "cpp" }
    Depends { name: "Qt.core" }
    Depends { name: "Qt.test" }

    Depends { name: "CppConcurrencyInAction_Lib" }
    Depends { name: "ValpineBase" }
}
