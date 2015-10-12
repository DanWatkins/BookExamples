#include <ValpineBase/Test.h>

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	vbase::test::Suite suite;
	suite.run(true);
	suite.cleanOldResults(60*5);
	suite.printResults();

	app.processEvents();

	return 0;
}
