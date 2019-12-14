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

	for (int i = 0; i < BOARD_ROWS; i++)
	{
		for (int j = 0; j < BOARD_COLS; j++)
		{
			ASSERT_EQ(pieza.pieceAt(i,j), Blank);
		}
	}
}

TEST(PiezasTest, pieceAtTestLimits)
{
	Piezas pieza;

	ASSERT_EQ(pieza.pieceAt(3,4), Invalid);
}

TEST(PiezasTest, pieceAtNegativeCol)
{
	Piezas pieza;

	ASSERT_EQ(pieza.pieceAt(0,-1), Invalid);
}

TEST(PiezasTest, pieceAtInvalidCol)
{
	Piezas pieza;

	ASSERT_EQ(pieza.pieceAt(0, 22), Invalid);
}

TEST(PiezasTest, pieceAtNegativeRow)
{
	Piezas pieza;

	ASSERT_EQ(pieza.pieceAt(-1,0), Invalid);
}

TEST(PiezasTest, pieceAtInvalidRow)
{
	Piezas pieza;

	ASSERT_EQ(pieza.pieceAt(15,0), Invalid);
}


TEST(PiezasTest, pieceAtOneDrop)
{
	Piezas pieza;
	pieza.dropPiece(2);

	ASSERT_EQ(pieza.pieceAt(0,2), X);
}

TEST(PiezasTest, pieceAtFullCol)
{
	Piezas pieza;

	pieza.dropPiece(1);
	pieza.dropPiece(1);
	pieza.dropPiece(1);

	ASSERT_EQ(pieza.pieceAt(2,1), X);
	ASSERT_EQ(pieza.pieceAt(1,1), O);
	ASSERT_EQ(pieza.pieceAt(0,1), X);
}

TEST(PiezasTest, pieceAtAfterReset)
{
	Piezas pieza;

	pieza.dropPiece(1);
	pieza.reset();
	ASSERT_EQ(pieza.pieceAt(0,1), Blank);
}

TEST(PiezasTest, pieceAtAfterResetAndDropPiece)
{
	Piezas pieza;

	pieza.dropPiece(1);
	pieza.reset();
	pieza.dropPiece(1);

	ASSERT_EQ(pieza.pieceAt(0,1), O);
}

TEST(PiezasTest, dropPieceFullRowAfterReset)
{
	Piezas pieza;

	pieza.dropPiece(0);
	pieza.reset();
	pieza.dropPiece(0);
	pieza.dropPiece(0);
	pieza.dropPiece(0);

	ASSERT_EQ(pieza.pieceAt(2,0), O);
}

TEST(PiezasTest, gameStateEmptyBoard)
{
	Piezas pieza;

	ASSERT_EQ(pieza.gameState(), Invalid);
}

TEST(PiezasTest, gameStateFullColumnsTie)
{
	Piezas pieza;

	for (int i = 0; i < BOARD_COLS; i++)
	{
		for (int j = 0; j < BOARD_ROWS; j++)
		{
			pieza.dropPiece(i);
		}
	}

	ASSERT_EQ(pieza.gameState(), Blank);
}

TEST(PiezasTest, gameStateFullHorizontalsForBothTie)
{
	Piezas pieza;

	for (int i = 0; i < BOARD_COLS; i++)
	{
		pieza.dropPiece(i);
		pieza.dropPiece(i);
	}
	for (int i = 0; i < BOARD_COLS; i++)
	{
		pieza.dropPiece(i);
	}

	ASSERT_EQ(pieza.gameState(), Blank);
}

TEST(PiezasTest, gameStateFullHorizontalXWinner)
{
	Piezas pieza;

	pieza.dropPiece(0);
	pieza.dropPiece(0);
	pieza.dropPiece(1);
	pieza.dropPiece(0);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(3);
	pieza.dropPiece(3);
	pieza.dropPiece(1);
	pieza.dropPiece(2);
	pieza.dropPiece(1);
	pieza.dropPiece(3);

	ASSERT_EQ(pieza.gameState(), X);
}

TEST(PiezasTest, gameStateAlternatingTie)
{
	Piezas pieza;

	for (int i = 0; i < BOARD_COLS; i++)
	{
		pieza.dropPiece(i);
	}
	for (int i = BOARD_COLS-1; i >= 0; i--)
	{
		pieza.dropPiece(i);
	}
	for (int i = 0; i < BOARD_COLS; i++)
	{
		pieza.dropPiece(i);
	}

	ASSERT_EQ(pieza.gameState(), Blank);
}

TEST(PiezasTest, gameStateColsWithThreeTie)
{
	Piezas pieza;

	pieza.dropPiece(0);
	pieza.dropPiece(0);
	pieza.dropPiece(1);
	pieza.dropPiece(1);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(0);
	pieza.dropPiece(3);
	pieza.dropPiece(3);
	pieza.dropPiece(1);
	pieza.dropPiece(2);
	pieza.dropPiece(3);

	ASSERT_EQ(pieza.gameState(), Blank);
}

TEST(PiezasTest, gameStateRowWithThreeWinO)
{
	Piezas pieza;

	pieza.dropPiece(0);
	pieza.dropPiece(0);
	pieza.dropPiece(1);
	pieza.dropPiece(2);
	pieza.dropPiece(3);
	pieza.dropPiece(2);
	pieza.dropPiece(1);
	pieza.dropPiece(1);
	pieza.dropPiece(0);
	pieza.dropPiece(2);
	pieza.dropPiece(3);
	pieza.dropPiece(3);

	ASSERT_EQ(pieza.gameState(), O);
}

TEST(PiezasTest, gameStateColAndRowWithThreeTie)
{
	Piezas pieza;

	pieza.dropPiece(1);
	pieza.dropPiece(0);
	pieza.dropPiece(2);
	pieza.dropPiece(0);
	pieza.dropPiece(3);
	pieza.dropPiece(0);
	pieza.dropPiece(1);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(3);
	pieza.dropPiece(3);
	pieza.dropPiece(1);

	ASSERT_EQ(pieza.gameState(), Blank);
}

TEST(PiezasTest, gameStateColWithThreeXWin)
{
	Piezas pieza;

	pieza.dropPiece(1);
	pieza.dropPiece(0);
	pieza.dropPiece(1);
	pieza.dropPiece(2);
	pieza.dropPiece(0);
	pieza.dropPiece(3);
	pieza.dropPiece(1);
	pieza.dropPiece(3);
	pieza.dropPiece(3);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(0);

	ASSERT_EQ(pieza.gameState(), X);
}