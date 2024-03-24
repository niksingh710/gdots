<p align="center" style="color:grey">

![image](https://github.com/niksingh710/gdots/assets/60490474/d8c152e5-8f4e-4b78-a386-31531584881f)

<div align="center">
<table>
<tbody>
<td align="center">
<img width="2000" height="0"><br>

These are my dot files for Graphical Instance on my system.<br>
I use **[Arch Linux](https://archlinux.org)** as My main OS and **[Hyprland](https://hyprland.org)** as my window manager.<br>
The configuration is highly dependent on **[pywal](https://github.com/dylanaraps/pywal)** i prefer a fork for 16-base colors **[pywal16](https://github.com/eylles/pywal16)** <br>

![GitHub repo size](https://img.shields.io/github/repo-size/niksingh710/gdots)
![GitHub Org's stars](https://img.shields.io/github/stars/niksingh710%2Fgdots)
![GitHub forks](https://img.shields.io/github/forks/niksingh710/gdots)
![GitHub last commit](https://img.shields.io/github/last-commit/niksingh710/gdots)

<img width="2000" height="0">
</td>
</tbody>
</table>
</div>
</p>

<details>
  <summary style="font-weight:bold;font-size:18px;">General Read</summary>

**If you are Reading this, you are probably interested in my dotfiles.<br> I have a few things to say before you start using them.**

> [!Note]
> I use autologin via `~/.zprofile`

```zsh
# Ensures me getting auto logged in into Hyprland
check() {
command -v "$1" &>/dev/null
}

check center-align && {
echo "$USER" | center-align
}

check Hyprland && {
pgrep -x Hyprland &>/dev/null || Hyprland &>/dev/null
} || {
echo "Hyprland Not found will not launch it as GUI instance"
}
```

<div align="center">
<table>
<tbody>
<td align="center">
<img width="2000" height="0"><br>

> <small>**GTK**: adw-gtk3 (gradience for colors) **KDE/QT**: Kvantum (pywal theme) <br> > [nwg-look-bin,qt6ct] </small><br>

<img width="2000" height="0">
</td>
</tbody>
</table>
</div>
</p>

- **Stow** : Stow is the tool i prefer to manage my dot files (i use `xstow` to be exact but it shouldn't matter).

  ```bash
  stow ./dir -t <target dir>
  ```

  e.g

  ```bash
  stow .config -t ~/.config
  ```

  Will create softlinks to all the dir inside repos `.config` to `~/.config/`

- **Pywal** : As i have mentioned earlier i use a pywal fork. It provides a 16 base color scheme.

  **pywal16** provides `.lighten(val%)` and `.darken(val%)` to lighten or darken the colors.
  I use them in my templates so normal `pywal` won't work here.

  ```bash
  wal -a 92 --cols16 darken --recursive -i ./path/to/wallpaper/or/dir -o after-wal
  ```

  <sub>You can check about `wal` command args by doing `wal --help`<sub>

  I want to grab your attention here for the `after-wal` script.

  - **after-wal** : This will be executed after wal command is executed. <br>
    The `wal` command will generate all the color schemes from the `~/.config/wal/templates/` dir and place them in `~/.cache/wal`.<br>
    It is the after wal command that places the color schemes in the right place and does the right thing.<br>
    e.g
    - It copies `colors-waybar.css` to `~/.config/waybar/colors.css` (this file is in .gitignore)
    - It copies kvantum theme with a name of `pywal` also takes care for dir creation.
    - It copies gradience theme with a name of `pywal` also takes care for dir creation.
    - It copies background image for firefox to `~/.mozilla/firefox/xxxx.default/chrome/`<br>
      This is acheived by placing a `bg` named file in the `mozilla` dir and then finding the file by using `fd` command and placing `wallpaper.png` to that dir
    - It generates a blurred version fo the wallpaper with name `~/.cache/wal-blurr.png`

  After executing stow you will find this command in you `~/.local/bin` dir.

</details>

### Prerequisites

> [!Note]
> Tools that are required to get the config working.<br>
> You can prefer `-git` version of the packages if something is not working.

##### Required:

```bash
yay -S hyprland hyprlock hypridle hyprpicker xdg-desktop-portal-hyprland hyprshade \
  gradience waybar rofi-lbonn-wayland-git libnotify mako \
  jq slurp grim grimblast-git hyprland-scratchpad-git xstow firefox firefox-pwa-bin \
  foot unzip unrar nwg-look-bin qt6ct kvantum zathura vimiv networkmanager bluez-utils \
  brightnessctl pipewire pipewire-pulse
```

> [!Note]
> For hyrshade check out their documentation for -> [hyprshade](https://github.com/loqusion/hyprshade)

##### Optional but Recommended

```bash
yay -S udiskie geoclue android-udev android-tools scrcpy networkmanager-dmenu-git kdeconnect mpv
```

### Setup

```
git clone -b master --single-branch https://github.com/niksingh710/gdots.git ~/.gdots
cd ~/.gdots
xstow .config -t ~/.config
xstow bin -t ~/.local/bin
```

### Previews

![image](https://github.com/niksingh710/gdots/assets/60490474/2abeda48-1349-4226-b46e-35e74dc4992f)

| ![image](https://github.com/niksingh710/gdots/assets/60490474/2abeda48-1349-4226-b46e-35e74dc4992f) | ![image](https://github.com/niksingh710/gdots/assets/60490474/3f5b2ac4-f27f-4363-980a-7c2a45eb2e91) |
| --------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------- |

Window opacty can be toggled using `Super+Shift+O`

<details>
  <summary style="font-size: 20px; font-weight: bold;"> More Previews </summary>

<video autoplay loop width="720" src="https://github.com/niksingh710/gdots/assets/60490474/5d53a696-e7cb-470e-bc76-f302a078bf8a"></video>

<video autoplay loop width="720" src="https://github.com/niksingh710/gdots/assets/60490474/b2ed9c4e-e971-4983-84a5-742e88c38ad5"></video>

</details>

#### Waybar

Waybar uses many scripts those should be available in `~/.local/bin` and waybar specific scripts are available in `bin` dir of waybar.

Waybar get's colors from a css file that get's copied there by `after-wal`

I have a keybind in my config that toggles it. `Super+b` -> `killall -SIGUSR1 waybar`

Waybar get's started by a script `~/.local/bin/bar.sh` that switches it's output based on connected monitors.

| ![image](https://github.com/niksingh710/gdots/assets/60490474/e6819215-54de-499d-bbd0-85742bdddf3f) | ![image](https://github.com/niksingh710/gdots/assets/60490474/2870a9e6-b6d6-4a07-8ab9-580858a6f628) | <video height="390" autoplay loop src="https://github.com/niksingh710/gdots/assets/60490474/7dbaf637-1ffd-4437-8eb2-489737ef6ee0"></video> |
| --------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------ |

<details>
  <summary style="font-size: 20px; font-weight: bold;"> More Previews </summary>

| <video height="1080" autoplay loop src="https://github.com/niksingh710/gdots/assets/60490474/7dbaf637-1ffd-4437-8eb2-489737ef6ee0">""</video> | Update Tooltip Preview ![image](https://github.com/niksingh710/gdots/assets/60490474/b55509a2-3cb2-4e32-9e73-62503689b2cf) |
| --------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------- |

</details>

#### Firefox

The Firefox theme i use is **[ShyFox](https://github.com/Naezr/ShyFox)**.
Checkout the documentation for the setup.
I have the current state of my theme in my `extra/chrome.shyfox` dir.
The theme is so nice that it has floating tabs url bar and much more. (Check further preview)

Keymaps i have setted up With my setup in my SideBerry and all of my extensions.
e.g:

- `Alt-J,K` : To switch in tabs
- `Ctrl-Shift-L` : To toggle the floating of sidebery

And Many more. Shortcuts are to be made by personal preference but then also if you feel i should list them or you want my one those are higly likely to be like vim ping on issue.

![image](https://github.com/niksingh710/gdots/assets/60490474/9cfed420-ef64-4d98-8e20-ff0ab1fa7b29)

<details>
  <summary style="font-size: 20px; font-weight: bold;"> More Previews </summary>

<video width="720" autoplay loop src="https://github.com/niksingh710/gdots/assets/60490474/ade74632-e7b3-4706-82de-1c46e8dddec8"></video>

| ![image](https://github.com/niksingh710/gdots/assets/60490474/6e4671bf-2c02-48a0-b210-471ac5c68944) | ![image](https://github.com/niksingh710/gdots/assets/60490474/58c9449c-0158-4db9-9406-34af8221f51a) |
| --------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------- |

![image](https://github.com/niksingh710/gdots/assets/60490474/acbc83be-364b-4eea-9d56-5ff72d72ce34)

</details>

<details>
  <summary style="font-size: 20px; font-weight: bold;">Rofi</summary>

| ![image](https://github.com/niksingh710/gdots/assets/60490474/52eddafd-9227-4d99-becc-5942ecd556db) | ![image](https://github.com/niksingh710/gdots/assets/60490474/46531dc3-f76f-499d-ad98-c085e77fbf5b) |
| --------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------- |

</details>

<p align="center" style="color:grey">

#### [Shell](https://github.com/niksingh710/cli)

> [!Note]
> Shell is seprate from this repository to keep it working on servers and other Os those are incompatible with this kind of graphical configuration state.

</p>
