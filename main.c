#include "structs.h"
#include <stdio.h>
#include <string.h>

typedef void (*ActionCallback)(Parameters *parameters);

void ActionPlay(Parameters *p_parameters) {
  p_parameters->game_state_ = kGameStatePlaying;
}
void ActionEnd(Parameters *p_parameters) {
  p_parameters->game_state_ = kGameStateEnd;
}
void ActionStart(Parameters *p_parameters) {
  p_parameters->game_state_ = kGameStateStart;
}

ActionCallback fsm_matrix[3][2] = {
    {NULL, ActionPlay},
    {NULL, ActionEnd},
    {NULL, ActionStart},
};

Signal GetSignal(const int code) {
  if (code == 10) {
    return kSignalNone;
  }
  return kSignal;
}

void SignalAction(Parameters *p_parameters, const Signal signal) {
  ActionCallback action_callback =
      fsm_matrix[p_parameters->game_state_][signal];
  if (action_callback) {
    action_callback(p_parameters);
  }
}

void PrintParameters(Parameters *p_parameters) {
  if (p_parameters->game_state_ == kGameStateStart) {
    printf("Current state: [%s]\n", "kGameStateStart");
  }
  if (p_parameters->game_state_ == kGameStatePlaying) {
    printf("Current state: [%s]\n", "kGameStatePlaying");
  }
  if (p_parameters->game_state_ == kGameStateEnd) {
    printf("Current state: [%s]\n", "kGameStateEnd");
  }
}

int main() {
  Parameters parameters = {0};
  parameters.game_state_ = kGameStateStart;

  while (1) {
    char code;
    scanf("%c", &code);
    Signal signal = GetSignal(code);

    SignalAction(&parameters, signal);

    PrintParameters(&parameters);
  }

  return 0;
}