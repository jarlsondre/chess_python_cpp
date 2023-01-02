from build import chess_module


def main():
    print(f"dir(chess_module): {dir(chess_module)}")
    pawn = chess_module.PyPawn("b")
    print(f"the color of pawn is {pawn.getColor()}")

    board = chess_module.PyBoard()
    board_pawn = board.getPiece(0, 0)
    print(board_pawn.getColor())


if __name__ == "__main__":
    main()
