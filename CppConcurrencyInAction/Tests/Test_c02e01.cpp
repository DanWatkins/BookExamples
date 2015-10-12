//=============================================================================|
// Copyright (C) 2015 Valpineware
// This file is licensed under the MIT License.
//=============================================================================|

#include <ValpineBase/Test.h>
#include <c02e01.h>

using namespace vbase;

class Test_c02e01 : public test::Class
{
	Q_OBJECT

private slots:
	VTEST void t1()
	{
		Post_Failure("Hello");
	}
};

ADD_TESTCLASS(Test_c02e01)
#include "Test_c02e01.moc"
