#include <ValpineBase/Test.h>

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	vbase::test::Suite suite;
	suite.run(true);
	suite.testResults().cleanOldResults(60*5);
	suite.testResults().printResults();

	app.processEvents();

	return 0;
}
