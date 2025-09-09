# QMK Keymap Improvements - Implementation Guide

## 🎯 Overview

Your improved QMK keymap now includes comprehensive Brazilian Portuguese accent support and productivity enhancements specifically designed for your Planck 47-key layout.

## ✨ Key Improvements

### 1. **Brazilian Accent Layer (Layer 8)**

**Access:** Hold the rightmost thumb key (replaced KC_HYPR)

**Accent Shortcuts:**

- `Layer8 + A` = **á** (a-acute)
- `Layer8 + Shift + A` = **à** (a-grave)
- `Layer8 + E` = **é** (e-acute)
- `Layer8 + I` = **í** (i-acute)
- `Layer8 + O` = **ó** (o-acute)
- `Layer8 + Shift + O` = **ô** (o-circumflex)
- `Layer8 + U` = **ú** (u-acute)
- `Layer8 + C` = **ç** (c-cedilla)
- `Layer8 + N` = **ñ** (n-tilde)

### 2. **Enhanced Navigation Layer (Layer 7)**

**Access:** Hold Space

**New Features:**

- **Window Management:** G(↑/↓/←/→) for window tiling
- **Enhanced Navigation:** Home/End, PgUp/PgDn optimized
- **Quick Actions:** Undo (Cmd+Z), Cut (Cmd+X), Copy (Cmd+C), Paste (Cmd+V)

### 3. **Programming/Development Layer (Layer 5)**

**Access:** Fn key (2nd thumb key from left)

**Development Shortcuts:**

- Common brackets: `{`, `}`, `[`, `]`, `(`, `)`
- Programming symbols: `|`, `&`, `*`, `_`, `+`, `<`, `>`, `#`, `$`, `%`, `^`
- Quick access to frequently used development characters

### 4. **Smart Macros & Features**

#### Tap Dance Accents (Alternative Method)

- Double-tap `A` → **á**, Triple-tap → **à**
- Double-tap `E` → **é**
- Double-tap `C` → **ç**

#### Programming Macros

- `EMAIL_MACRO`: Inserts your email address
- `ARROW_FUNC`: Inserts `() => {}` (JavaScript arrow function)
- `CONSOLE_LOG`: Inserts `console.log()`
- `REACT_COMP`: Generates React component template

## 📁 Files Created/Modified

1. **`planck-rev7-improved.json`** - New enhanced keymap
2. **`config.h`** - Updated with Unicode and tap dance settings
3. **`rules.mk`** - Enabled Unicode and tap dance features
4. **`source.c`** - Advanced custom functions and macros

## 🚀 Installation Steps

### Method 1: Using the New JSON File

```bash
# Copy the improved keymap
cp planck-rev7-improved.json planck-rev7.json

# Or rename for clarity
mv planck-rev7.json planck-rev7-original.json
mv planck-rev7-improved.json planck-rev7.json

# Compile and flash
qmk compile planck-rev7.json
qmk flash planck-rev7.json
```

### Method 2: Manual Integration

1. **Backup your current setup:**

   ```bash
   cp planck-rev7.json planck-rev7-backup.json
   ```

2. **Apply the layer changes** to your existing `planck-rev7.json`:

   - Update thumb cluster: Change `KC_HYPR` to `MO(8)`
   - Replace Layer 5 (Plover) with Development layer
   - Replace Layer 8 (Function) with Accent layer
   - Enhance Layer 7 (Navigation) with new shortcuts

3. **Update configuration files** (already done):
   - `config.h` - Unicode settings
   - `rules.mk` - Feature enables
   - `source.c` - Custom functions

## 🛠 Customization Options

### Personalizing Accents

Edit `source.c` to modify accent mappings:

```c
// Example: Adding more accents
[A_TILDE] = 0x00E3,  // ã
[O_TILDE] = 0x00F5,  // õ
```

### Adding Custom Macros

```c
case YOUR_MACRO:
    if (record->event.pressed) {
        SEND_STRING("Your custom text here");
    }
    return false;
```

### Adjusting Tap Dance Timing

In `config.h`:

```c
#define TAPPING_TERM 200  // Adjust timing (milliseconds)
```

## 💡 Usage Tips

### Efficient Brazilian Typing

1. **Hold accent layer** (rightmost thumb) while typing vowels
2. **Quick ç:** Hold accent layer + C
3. **Capital letters:** Use Shift while in accent layer for uppercase accents

### Development Workflow

1. **Quick symbols:** Use development layer for brackets and operators
2. **Arrow functions:** Use macro for rapid JavaScript development
3. **Navigation:** Hold space for enhanced text navigation

### Window Management (macOS)

1. **Tile windows:** Navigation layer + arrow keys
2. **Quick copy/paste:** Navigation layer shortcuts
3. **Page navigation:** Optimized PgUp/PgDn placement

## 🔧 Troubleshooting

### Unicode Issues

If accents don't work:

1. **macOS:** Should work automatically
2. **Linux:** You may need `UC_LNX` mode
3. **Windows:** You may need `UC_WIN` mode

Change mode in `source.c`:

```c
void keyboard_post_init_user(void) {
    unicode_config.input_mode = UC_LNX;  // or UC_WIN
}
```

### Compilation Issues

If compilation fails:

```bash
# Clean and retry
qmk clean
qmk compile planck-rev7.json
```

## 📊 Performance Impact

**Features Added:**

- ✅ Unicode support (+minimal memory)
- ✅ Tap dance (+small memory)
- ✅ Custom macros (+small memory)
- ✅ Enhanced layer logic (+minimal processing)

**Total Impact:** Negligible - all features are lightweight and optimized.

## 🎯 Next Steps

1. **Test the improved layout** with your daily workflow
2. **Customize macros** with your specific email/snippets
3. **Adjust tap dance timing** to your preference
4. **Consider additional layers** for specific use cases (music, gaming, etc.)

## 📚 Quick Reference

### Layer Access Summary

- **Layer 0:** QWERTY (base)
- **Layer 1:** Colemak
- **Layer 2:** Dvorak
- **Layer 3:** Lower (symbols + F1-F6)
- **Layer 4:** Raise (numbers + F7-F12)
- **Layer 5:** Development (programming symbols)
- **Layer 6:** Adjust (system controls)
- **Layer 7:** Navigation (enhanced with window management)
- **Layer 8:** Brazilian Accents (the star of the show! ⭐)

### Thumb Cluster Layout

```
(/Ctrl | Dev(5) | Opt | Cmd | Lower(3) | Space/Nav(7) | Raise(4) | Cmd | Opt | Accent(8) | )/Ctrl
```

---

**Enjoy your enhanced Brazilian Portuguese typing experience! 🇧🇷⌨️**
