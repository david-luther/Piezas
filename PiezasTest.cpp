/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, dropPieceOnePiece)
{
	Piezas pieza;

	ASSERT_EQ(pieza.dropPiece(0), X);
}

TEST(PiezasTest, dropPieceTwoPieces)
{
	Piezas pieza;
	pieza.dropPiece(1);

	ASSERT_EQ(pieza.dropPiece(1), O);
}

TEST(PiezasTest, dropPieceNegativeCol)
{
	Piezas pieza;

	ASSERT_EQ(pieza.dropPiece(-1), Invalid);
}

TEST(PiezasTest, dropPieceInvalidCol)
{
	Piezas pieza;

	ASSERT_EQ(pieza.dropPiece(4), Invalid);
}

TEST(PiezasTest, dropPieceFullCol)
{
	Piezas pieza;
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(2);


	ASSERT_EQ(pieza.dropPiece(2), Blank);
}