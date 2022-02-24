/*
  ==============================================================================

    ZxLookAndFeel.h
    Created: 23 Feb 2022 10:54:01am
    Author:  ZECHS

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ColourPalette.h"

class ZxLookAndFeel : public LookAndFeel_V4
{
public:
    ZxLookAndFeel();

    static Colour getBGColour();

    void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
        float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override;

    void drawLinearSlider(Graphics& g, int x, int y, int width, int height, 
        float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle, Slider&) override;

    void drawGroupComponentOutline(Graphics& g, int w, int h, const String& text, const Justification&, GroupComponent&) override;

    void drawToggleButton(Graphics& g, ToggleButton& button, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;

    void drawButtonBackground(Graphics& g, Button& button, const Colour &backgroundColour, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;
};

