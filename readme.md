# FW16 OpenRGB Guide

I recently picked up my Framework 16, and wanted to run OpenRGB on it so I could make my RGB keyboard synced with my audio. I've figured it out, so here's a brief rundown on installing OpenRGB (in this example on Fedora), setting up a QMK environment, compiling and flashing your board.

PLEASE NOTE: VIA DOES **NOT** WORK WITH OPENRGB!

You can find precompiled binaries for the RGB ANSI Keyboard and the RGB Macropad [HERE](https://github.com/Knucklesfan/qmk_firmware.git):

If you somehow screw this up, Framework's official binaries can be found [HERE](https://github.com/FrameworkComputer/qmk_firmware/releases)

## If you choose to compile it yourself (**RECOMMENDED**), follow the following steps in order. Otherwise, you can skip to Step 4 and use the precompiled binaries.

# 1. Compilation First Steps
You're gonna need the bare essentials, which is a set-up QMK environment. These are the steps I followed to setup QMK, but if you run into any issues or this guide is outdated in whatever way, you can read the official documentation on setting up for your distro/os of choice [HERE](https://docs.qmk.fm/newbs_getting_started)

First, install git and python (with pip):
    - Debian / Ubuntu / Devuan: `sudo apt install -y git python3-pip`
    - Fedora / Red Hat / CentOS: `sudo yum -y install git python3-pip`
    - Arch / Manjaro: `sudo pacman --needed --noconfirm -S git python-pip libffi`
    - Void: `sudo xbps-install -y git python3-pip`
    - Solus: `sudo eopkg -y install git python3`
    - Sabayon: `sudo equo install dev-vcs/git dev-python/pip`
    - Gentoo: `sudo emerge dev-vcs/git dev-python/pip`

Next, you should install the QMK CLI running:
```
python3 -m pip install --user qmk
```

# 2. Downloading the repo

Before running `qmk setup`, you should probably have my repo downloaded. I've pushed my fix for direct mode to https://github.com/tagno25/qmk_firmware, but as of writing have not been merged yet. To download my repository, run

```
git clone https://github.com/Knucklesfan/qmk_firmware.git
```

Now, run `cd qmk_firmware` and you're ready to run `qmk setup`!
If you get mild warnings, some of those are to be expected.
Whenever I first setup QMK on my fedora install, qmk complains of "avr-gcc" being too new (which does not matter for the fw16's boards anyways), and that git is not configured upstream. You can ignore both of these issues. You may also see warnings telling you to setup udev devices, while I recommend doing this, its not essential for the fw16 for reasons we'll get to in a moment.

# 3. Compiling

Compilation is really easy. The following should be used for compiling with OpenRGB on the following keyboards
- RGB Macropad `qmk compile -kb framework/macropad -km openrgb`
- RGB Keyboard `qmk compile -kb framework/ansi -km openrgb`
Once compilation is finished, you can find the compiled firmwares in the root directory of the firmware git repo.

# 4. Flashing

You can find precompiled binaries for the RGB ANSI Keyboard and the RGB Macropad [HERE](https://github.com/Knucklesfan/qmk_firmware.git):

If you somehow screw this up, Framework's official binaries can be found [HERE](https://github.com/FrameworkComputer/qmk_firmware/releases)
Both the official and unofficial binaries flash the exact same way.

Flashing is relatively easy. All Framework QMK devices have similar reset activations. The following are the ones for the RGB Macropad and the RGB Keyboard (the only ones that really matter to this guide, but these apply to most framework keyboard devices)

## WARNING: It is recommended to do these one at a time. Doing both together means you can't tell the difference between the two devices and might accidentally flash the wrong firmware (that's bad)

To power cycle the FW keyboards, remove the touchpad which will turn off power to all keyboard/macropad devices. Next, press and hold the reset buttons as described below.
- RGB Macropad: Hold down the 6 and 2 keys while powering on the keyboard. The 6 key is positioned at (2,3) and the 2 key is positioned at (1,4), with the top left key being (0,0)
- RGB Keyboard: Hold down the left and right ALT Keys
Finally, slide the touchpad back in while holding the reset keys. This will repower the device and put it into reset mode. To disable reset mode without flashing, just remove the touchpad and put it back.

Once into reset mode, a new drive should show up for flashing, called `RPI-RP2`, and should show up like a USB drive. To flash, drag the compiled or downloaded firmware file into this drive, and the device will automatically flash! With any luck, it should power back on with the new firmware

# 5. Installing OpenRGB

Once you've flashed your hardware, you should now find that VIA does not work. You can still change keymaps and macros, but it does require some code modification. (it's really not much... Any basic C knowledge will get you a long way)

Next, we should set up OpenRGB. First, install OpenRGB via your distro's package manager. For example, on Fedora, you would run
```
sudo dnf install openrgb
```
For other distros, please see [the OpenRGB documentation](https://openrgb.org/#downloads)

Once you boot up OpenRGB for the first time, it'll complain of missing udev rules. You should ensure that you reboot after installing these udev rules. If OpenRGB still complains, it's probably fine? Especially if it complains of missing I2C devices, as the FW16 doesnt have any I2C RGB devices, this warning can be ignored. [Please read this for more information if you have any issues](https://openrgb.org/udev.html) (you shouldn't have any issues if you just install openrgb and reboot)

# 6. Setting Up OpenRGB

OpenRGB is pretty easy to setup. Once you've installed and launched it, the following is the easy steps on setting this up:

    1. Go to the settings tab
    2. Scroll down to OpenRGB QMK Protocol in the side list
    3. Add your devices.

When adding these devices, you should set them up like the following table:

|         | Keyboard                                   | Macropad                         |
|---------|--------------------------------------------|----------------------------------|
| Name    | Framework Laptop 16 Keyboard Module - ANSI | Framework Laptop 16 RGB Macropad |
| USB VID | 32ac                                       | 32ac                             |
| USB PID | 0012                                       | 0013                             |

Next, you should click "Save", then "Save Profile" and save to a profile. Then, you can restart OpenRGB. OpenRGB should be working now! All features are supported, including Direct Mode!

# Troubleshooting

Q: Help! Whenever I start OpenRGB after setting up the keyboard in QMK, it hangs forever and stops responding
A: Make sure you compiled the firmware with the keymap `openrgb` and not `default` or any others.

Q: OpenRGB gives me an I2C/USB error, and the keyboard doesn't work
A: You need to make sure that you restarted after installing the udev rules. If you're using the flatpak or appimage, you'll need to manually install the OpenRGB I2C/USB UDEV rules. You can find more [here](https://openrgb.org/udev.html)

Q: How can I go back to the stock firmware?
A: Links to the stock firmware and instructions on flashing is provided during step 4

Q: Does this void my warranty?
A: I have no idea. I don't think it's possible to brick the keyboard, so probably not? It's not like the flashing can detected anyways.

Q: Is there any way to get VIA to work with OpenRGB?
A: I doubt it. Projects like VIAL exist, but VIAL will need a lot more work to get to work with the FW16.

Q: How'd you do that cool visualizer from the video?
A: [It's OpenRGB Effects from the plugins list!](https://openrgb.org/plugins.html)

Q: I bricked my computer, can i come over to your house and beat the crap out of you?
A: Please don't

If you have any issues with this guide, or my fork, let me know!

# THIS IS THE DEVELOP BRANCH

Warning- This is the `develop` branch of QMK Firmware. You may encounter broken code here. Please see [Breaking Changes](https://docs.qmk.fm/#/breaking_changes) for more information.

# Quantum Mechanical Keyboard Firmware

[![Current Version](https://img.shields.io/github/tag/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/tags)
[![Discord](https://img.shields.io/discord/440868230475677696.svg)](https://discord.gg/Uq7gcHh)
[![Docs Status](https://img.shields.io/badge/docs-ready-orange.svg)](https://docs.qmk.fm)
[![GitHub contributors](https://img.shields.io/github/contributors/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/qmk/qmk_firmware.svg?style=social&label=Fork)](https://github.com/qmk/qmk_firmware/)

This is a keyboard firmware based on the [tmk\_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](https://ergodox-ez.com) keyboard, and the [Clueboard product line](https://clueboard.co).

## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are powered by [Docsify](https://docsify.js.org/) and hosted on [GitHub](/docs/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls), or by clicking the "Edit this page" link at the bottom of any page.

## Supported Keyboards

* [Planck](/keyboards/planck/)
* [Preonic](/keyboards/preonic/)
* [ErgoDox EZ](/keyboards/ergodox_ez/)
* [Clueboard](/keyboards/clueboard/)
* [Cluepad](/keyboards/clueboard/17/)
* [Atreus](/keyboards/atreus/)

The project also includes community support for [lots of other keyboards](/keyboards/).

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
