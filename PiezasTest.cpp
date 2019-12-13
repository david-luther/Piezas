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

TEST(PiezasTest, dropPieceFullReset)
{
	Piezas pieza;
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.reset();

	ASSERT_EQ(pieza.dropPiece(2), O);
}

TEST(PiezasTest, pieceAtEmptyBoard)
{
	Piezas pieza;

	ASSERT_EQ(pieza.pieceAt(0,0), Blank);
	ASSERT_EQ(pieza.pieceAt(0,3), Blank);
	ASSERT_EQ(pieza.pieceAt(2,3), Blank);
	ASSERT_EQ(pieza.pieceAt(2,0), Blank);
}

TEST(PiezasTest, pieceAtInvalidVals)
{
	Piezas pieza;

	ASSERT_EQ(pieza.pieceAt(-1,0), Invalid);
	ASSERT_EQ(pieza.pieceAt(0,-1), Invalid);
	ASSERT_EQ(pieza.pieceAt(15,0), Invalid);
	ASSERT_EQ(pieza.pieceAt(0, 22), Invalid);
	ASSERT_EQ(pieza.pieceAt(3,4), Invalid);
}

TEST(PiezasTest, pieceAtOneDrop)
{
	Piezas pieza;
	pieza.dropPiece(2);

	ASSERT_EQ(pieza.pieceAt(0,2), X);
	ASSERT_EQ(pieza.pieceAt(0,0), Blank);
}

TEST(PiezasTest, pieceAtFullCol)
{
	Piezas pieza;

	pieza.dropPiece(1);
	pieza.dropPiece(1);
	pieza.dropPiece(1);

	ASSERT_EQ(pieza.pieceAt(2,1), X);
	ASSERT_EQ(pieza.pieceAt(1,1), O);
	ASSERT_EQ(pieza.pieceAt(1,0), X);
}

TEST(PiezasTest, pieceAtAfterReset)
{
	Piezas pieza;

	pieza.drop(0);

}