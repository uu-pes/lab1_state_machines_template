#include "pico/stdlib.h"
/* !!! PART 2 & 3 !!! */

/* !!! MIGHT WANT TO CHANGE THIS !!! */
#define BUTTON_DEBOUNCE_DELAY   00

/* Function pointer primitive */ 
typedef void (*state_func_t)( void );

typedef struct _state_t
{
    uint8_t id;
    state_func_t Enter;
    state_func_t Do;
    state_func_t Exit;
    uint32_t delay_ms;
} state_t;

typedef enum _event_t 
{
    b1_evt = 0,
    b2_evt = 1,
    b3_evt = 2,
    no_evt = 3
} event_t;

/* !!! PART 2 & 3 !!! */
/* Define event queue */

void button_isr(uint gpio, uint32_t events) 
{
    /* !!! PART 2 !!! */
    return; 
}

void private_init() 
{
    /* !!! PART 2 !!! */
    /* Event queue setup */ 

    /* !!! PART 2 !!! */
    /* Button setup */

    /* !!! PART 1 !!! */
    /* LED setup */
}

/* The next three methods are for convenience, you might want to use them. */
event_t get_event(void)
{
    /* !!!! PART 2 !!!! */
    return (event_t) no_evt;
}

void leds_off () 
{
    /* !!! PART 1 !!! */
}

void leds_on () 
{
    /* !!! PART 2 !!! */
}

void do_state_0(void)
{
    /* !!! PART 1 !!! */
}

/* !!! PART 1 !!! */
const state_t state0 = {
    0, 
    NULL,
    do_state_0,
    NULL, 
    500
};

/* !!! PART 2 !!! */
// const state_t state_table[][] = {};

/* !!! ALL PARTS !!! */
int main() 
{
    private_init(); 

    state_t current_state = state0;
    event_t evt = no_evt;

    for(;;) 
    {
        current_state.Enter();
        evt = get_event();

        while(1)
        {
            current_state.Do();
            sleep_ms(current_state.delay_ms);
            evt = get_event();
        }
        current_state.Exit();
    }
}
