# Libftx

A `libftx` é uma biblioteca desenvolvida para simplificar o uso da `minilibx` em projetos gráficos, oferecendo uma interface mais intuitiva e poderosa para a criação de janelas, manipulação de eventos e outras operações gráficas.

## Instalação

1. **Clone o Repositório**:
    ```bash
    git clone https://github.com/xmaj2001/libftx.git
    cd libftx
    ```

2. **Compile a Biblioteca**:
    ```bash
    make
    ```

3. **Inclua a Biblioteca no Seu Projeto**:
    Adicione a linha abaixo no seu `Makefile` ou no comando de compilação:
    ```bash
    -L/path/para/libftx -lftx
    ```

4. **Inclua o Cabeçalho no Seu Código**:
    ```c
    #include "libftx.h"
    ```

## Uso Básico

### Criando uma Janela

Exemplo:
```c
#include <libftx.h>

int main(void)
{
	t_window	*window;
	window = ft_create_window("LIBFTX", 1000, 800, BLACK);
	ft_start_window(window);
    return (0);
}

```
### Manipulação de Eventos

A biblioteca `libftx` oferece diversas formas de manipulação de eventos, cada uma com suas funções específicas:

#### Teclado

```c
ft_hook_keyup(window, test_keyup, NULL);
ft_hook_keyrelease(window, test_release, NULL);
ft_hook(window, KeyPress_EVENT, test_press, NULL);
```
#### Mouse

```c
ft_hook(window, MouseEnter_EVENT, test_mouse_enter, NULL);
ft_hook(window, MouseLeave_EVENT, test_mouse_leave, NULL);
ft_hook(window, MouseMove_EVENT, test_mouse_move, NULL);
```

### Exemplo Manipulando Eventos

```c
#include "libftx.h"

int test_keyup(int key, void *param)
{
    if (KEY_U == key)
        ft_printf("Pression KEY UP\n");
    return (0);
}
int test_mouse_enter(int x, int y, void *param)
{
    ft_printf("mouse enter: position x:%d y:%d\n", x, y);
    return (0);
}

int main(void)
{
    t_window window;

    window.title = "LIBFTX";
    window.background = DARK_PURPLE;
    window.width = 1000;
    window.height = 600;

    ft_create_windows(&window);
    ft_hook_keyup(&window, test_keyup, NULL);
    ft_hook(&window, MouseEnter_EVENT, test_mouse_enter, NULL);
    ft_start_window(&window);
    return (0);
}

```

### Teclas Disponíveis na Libftx

As teclas na libftx são definidas com nomes simbólicos para facilitar o uso em eventos. Aqui estão algumas das teclas disponíveis:

- Letras de A a Z:
  - `KEY_A`: 97
  - `KEY_B`: 98
  - `KEY_C`: 99
  - `KEY_D`: 100
  - `KEY_E`: 101
  - `KEY_F`: 102
  - `KEY_G`: 103
  - `KEY_H`: 104
  - `KEY_I`: 105
  - `KEY_J`: 106
  - `KEY_K`: 107
  - `KEY_L`: 108
  - `KEY_M`: 109
  - `KEY_N`: 110
  - `KEY_O`: 111
  - `KEY_P`: 112
  - `KEY_Q`: 113
  - `KEY_R`: 114
  - `KEY_S`: 115
  - `KEY_T`: 116
  - `KEY_U`: 117
  - `KEY_V`: 118
  - `KEY_W`: 119
  - `KEY_X`: 120
  - `KEY_Y`: 121
  - `KEY_Z`: 122

- Números de 0 a 9:
  - `KEY_NUM0`: 48
  - `KEY_NUM1`: 49
  - `KEY_NUM2`: 50
  - `KEY_NUM3`: 51
  - `KEY_NUM4`: 52
  - `KEY_NUM5`: 53
  - `KEY_NUM6`: 54
  - `KEY_NUM7`: 55
  - `KEY_NUM8`: 56
  - `KEY_NUM9`: 57


### Cores Disponíveis na Libftx

As cores na libftx são representadas por valores hexadecimais. Aqui estão algumas das cores disponíveis:

- `WHITE`: 0xFFFFFF
- `BLACK`: 0x000000
- `RED`: 0xFF0000
- `GREEN`: 0x00FF00
- `BLUE`: 0x0000FF
- `YELLOW`: 0xFFFF00
- `CYAN`: 0x00FFFF
- `MAGENTA`: 0xFF00FF
- `ORANGE`: 0xFFA500
- `PINK`: 0xFFC0CB
- `PURPLE`: 0x800080
- `BROWN`: 0xA52A2A
- `GRAY`: 0x808080
- `LIGHT_GRAY`: 0xD3D3D3
- `DARK_GRAY`: 0xA9A9A9
- `NAVY`: 0x000080
- `TEAL`: 0x008080
- `OLIVE`: 0x808000
- `MAROON`: 0x800000
- `LIME`: 0xBFFF00
- `INDIGO`: 0x4B0082
- `GOLD`: 0xFFD700
- `SILVER`: 0xC0C0C0
- `BEIGE`: 0xF5F5DC
- `LIGHT_BLUE`: 0xADD8E6
- `LIGHT_GREEN`: 0x90EE90
- `LIGHT_PINK`: 0xFFB6C1
- `LIGHT_YELLOW`: 0xFFFFE0
- `DARK_BLUE`: 0x00008B
- `DARK_RED`: 0x8B0000
- `DARK_GREEN`: 0x006400
- `DARK_ORANGE`: 0xFF8C00
- `DARK_PURPLE`: 0x6A0DAD

