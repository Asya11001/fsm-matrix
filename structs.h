#ifndef FSM_MATRIX__STRUCTS_H_
#define FSM_MATRIX__STRUCTS_H_

typedef enum{
  kGameStateStart = 0,
  kGameStatePlaying = 1,
  kGameStateEnd = 2,
} GameState;

typedef enum {
  kSignalNone = 0,
  kSignal = 1,
} Signal;

typedef struct {
  GameState game_state_;
} Parameters;


#endif // FSM_MATRIX__STRUCTS_H_
