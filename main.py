from build import chess_module


def main():
    # print(f"dir(chess_module): {dir(chess_module)}")
    # pawn = chess_module.PyPawn("b")
    # print(f"the color of pawn is {pawn.getColor()}")

    board = chess_module.PyBoard()
    # print(board_pawn.getColor())
    # init_state = board.getBoardString()
    # new_state = board.getBoardString()

    # print(init_state)
    # print(new_state)
    pawns = []
    for i in range(8):
        for j in range(8):
            pawn = board.getPiece(j, i)
            print(pawn)
            pawns.append(pawn)

    board.movePiece(0, 0, 4, 4)
    state_1 = board.getBoardString()
    board.movePiece(4, 4, 0, 0)
    state_2 = board.getBoardString()
    print(len(pawns))
    print(len(set(pawns)))

    print(state_1)
    print(state_2)


if __name__ == "__main__":
    main()
