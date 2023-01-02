from build import chess_module


def main():
    print(f"dir(chess_module): {dir(chess_module)}")
    pawn = chess_module.PyPawn("b", "Jarlinator")
    print(f"The name of the piece is {pawn.getName()}")

    pawn.setName("Jarlinator2")
    print(f"The name of the piece is {pawn.getName()}")

    board = chess_module.PyBoard()
    board_pawn = board.getPiece(0, 0)
    print(board_pawn.getColor())
    # num_moves = board_pawn.getNumMoves()
    # print(f"num_moves: {num_moves}")


if __name__ == "__main__":
    main()
