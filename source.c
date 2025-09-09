#include QMK_KEYBOARD_H

// Brazilian Portuguese accent definitions
enum unicode_names {
    // Lowercase accented vowels
    A_ACUTE,    // á - 0x00E1
    A_GRAVE,    // à - 0x00E0
    E_ACUTE,    // é - 0x00E9
    I_ACUTE,    // í - 0x00ED
    O_ACUTE,    // ó - 0x00F3
    O_CIRCUM,   // ô - 0x00F4
    U_ACUTE,    // ú - 0x00FA
    C_CEDILLA,  // ç - 0x00E7
    N_TILDE,    // ñ - 0x00F1
    // Uppercase variants
    A_ACUTE_UP, // Á - 0x00C1
    A_GRAVE_UP, // À - 0x00C0
    E_ACUTE_UP, // É - 0x00C9
    I_ACUTE_UP, // Í - 0x00CD
    O_ACUTE_UP, // Ó - 0x00D3
    O_CIRCUM_UP,// Ô - 0x00D4
    U_ACUTE_UP, // Ú - 0x00DA
    C_CEDILLA_UP,// Ç - 0x00C7
    N_TILDE_UP  // Ñ - 0x00D1
};

const uint32_t PROGMEM unicode_map[] = {
    [A_ACUTE]    = 0x00E1, // á
    [A_GRAVE]    = 0x00E0, // à
    [E_ACUTE]    = 0x00E9, // é
    [I_ACUTE]    = 0x00ED, // í
    [O_ACUTE]    = 0x00F3, // ó
    [O_CIRCUM]   = 0x00F4, // ô
    [U_ACUTE]    = 0x00FA, // ú
    [C_CEDILLA]  = 0x00E7, // ç
    [N_TILDE]    = 0x00F1, // ñ
    [A_ACUTE_UP] = 0x00C1, // Á
    [A_GRAVE_UP] = 0x00C0, // À
    [E_ACUTE_UP] = 0x00C9, // É
    [I_ACUTE_UP] = 0x00CD, // Í
    [O_ACUTE_UP] = 0x00D3, // Ó
    [O_CIRCUM_UP]= 0x00D4, // Ô
    [U_ACUTE_UP] = 0x00DA, // Ú
    [C_CEDILLA_UP]=0x00C7, // Ç
    [N_TILDE_UP] = 0x00D1  // Ñ
};

// Custom keycodes for macros
enum custom_keycodes {
    EMAIL_MACRO = SAFE_RANGE,
    DATE_MACRO,
    ARROW_FUNC,
    CONSOLE_LOG,
    REACT_COMP
};

// Tap dance declarations
enum tap_dance_codes {
    TD_A_ACUTE,
    TD_E_ACUTE,
    TD_I_ACUTE,
    TD_O_ACUTE,
    TD_U_ACUTE,
    TD_C_CEDILLA
};

// Tap dance functions for accent shortcuts
void td_a_acute(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_A);
    } else if (state->count == 2) {
        send_unicode_hex_string("00E1"); // á
    } else if (state->count == 3) {
        send_unicode_hex_string("00E0"); // à
    }
}

void td_e_acute(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_E);
    } else if (state->count == 2) {
        send_unicode_hex_string("00E9"); // é
    }
}

void td_c_cedilla(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_C);
    } else if (state->count == 2) {
        send_unicode_hex_string("00E7"); // ç
    }
}

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_A_ACUTE]   = ACTION_TAP_DANCE_FN(td_a_acute),
    [TD_E_ACUTE]   = ACTION_TAP_DANCE_FN(td_e_acute),
    [TD_C_CEDILLA] = ACTION_TAP_DANCE_FN(td_c_cedilla),
};

// Custom macro processing
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EMAIL_MACRO:
            if (record->event.pressed) {
                // Replace with your email
                SEND_STRING("your.email@example.com");
            }
            return false;

        case DATE_MACRO:
            if (record->event.pressed) {
                // Current date format: DD/MM/YYYY
                SEND_STRING(SS_LCTL("c")); // Copy current selection first
                wait_ms(100);
                // You can customize this to insert current date
                SEND_STRING(__DATE__);
            }
            return false;

        case ARROW_FUNC:
            if (record->event.pressed) {
                SEND_STRING("() => {}");
                tap_code(KC_LEFT);
                tap_code(KC_LEFT);
                tap_code(KC_LEFT);
                tap_code(KC_LEFT);
                tap_code(KC_LEFT);
            }
            return false;

        case CONSOLE_LOG:
            if (record->event.pressed) {
                SEND_STRING("console.log()");
                tap_code(KC_LEFT);
            }
            return false;

        case REACT_COMP:
            if (record->event.pressed) {
                SEND_STRING("const Component = () => {" SS_TAP(X_ENTER) SS_TAP(X_TAB) "return (" SS_TAP(X_ENTER) SS_TAP(X_TAB) SS_TAP(X_TAB) "<div></div>" SS_TAP(X_ENTER) SS_TAP(X_TAB) ");" SS_TAP(X_ENTER) "};");
            }
            return false;
    }
    return true;
}

// Custom tapping term per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD_A_ACUTE:
        case TD_E_ACUTE:
        case TD_C_CEDILLA:
            return 150; // Shorter for accent tap dances
        default:
            return TAPPING_TERM;
    }
}

// Initialize unicode mode for macOS by default
void keyboard_post_init_user(void) {
    unicode_config.input_mode = UC_MAC;
}
