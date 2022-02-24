/*
  ==============================================================================

    ZxLookAndFeel.cpp
    Created: 23 Feb 2022 10:53:39am
    Author:  ZECHS

  ==============================================================================
*/

#include "ZxLookAndFeel.h"

//==============================================================================
// THEME CONFIG
//==============================================================================
namespace Theme = ColourPalette::Oil;

const float fontSize = 14.f;

ZxLookAndFeel::ZxLookAndFeel()
{
    //setColour(ResizableWindow::ColourIds::backgroundColourId, Theme::bgMain);
}

Colour ZxLookAndFeel::getBGColour()
{
    return Theme::bgMain;
}

void ZxLookAndFeel::drawRotarySlider(Graphics& g,
    int x, int y, int width, int height, float sliderPos,
    float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{
    height -= fontSize * 2;
    const float radius = jmin(width / 2, height / 2) * 0.85f;
    const float centreX = x + width * 0.5f;
    const float centreY = y + height * 0.5f + fontSize * 2;
    const float rx = centreX - radius;
    const float ry = centreY - radius;
    const float rw = radius * 2.0f;
    float fwidth = (float)width;
    float fheight = (float)height;
    const float angle = rotaryStartAngle
        + sliderPos
        * (rotaryEndAngle - rotaryStartAngle);

    // Draw Title
    String title = slider.getName();
    g.setColour(Theme::mainText);
    g.setFont(fontSize);
    g.drawFittedText(title, 0, 0, width, fontSize*2, Justification::centredBottom, 1, 1.f);

    // Draw BG Path
    g.setColour(Theme::bgComponent);
    Path filledArc;
    filledArc.addPieSegment(rx, ry, rw + 1, rw + 1, rotaryStartAngle, rotaryEndAngle, 0.6);
    g.fillPath(filledArc);

    // Draw Active Path
    g.setColour(Theme::compFace);
    Path filledArc1;
    filledArc1.addPieSegment(rx, ry, rw + 1, rw + 1, rotaryStartAngle, angle, 0.6);
    g.fillPath(filledArc1);

    // Draw Thumb
    Path p;
    const float pointerLength = radius * 0.63f;
    const float pointerThickness = radius * 0.2f;
    p.addRectangle(-pointerThickness * 0.5f, -radius - 1, pointerThickness, pointerLength);
    p.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));
    g.setColour(Theme::compHighlight);
    g.fillPath(p);
}

void ZxLookAndFeel::drawGroupComponentOutline(Graphics& g, int w, int h, const String& text, const Justification& justification, GroupComponent& group)
{
    auto margins = 5.f;

    // Draw BG
    g.setColour(Theme::bgGroup);
    g.fillRoundedRectangle(0 + margins, 0 + margins, w - margins * 2, h - margins * 2, 10.f);

    // Draw Text
    g.setColour(Theme::mainText);
    g.drawFittedText("GROUP", 0 + margins, 0 + margins, w - margins * 2, h - margins * 2, Justification::centredTop, 1, 1.f);
}

void ZxLookAndFeel::drawLinearSlider(Graphics& g, int x, int y, int width, int height,
    float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider)
{
    const float barWidth = 20.f;

    const float fwidth = width;
    const float fheight = slider.getLocalBounds().getHeight() - 10.f;

    const float centreX = width / 2.f - barWidth/2.f;
    const float centreY = y;

    const float botDisplacement = 20.f;
    const float topDisplacement = fontSize * 2 + 5.f;

    // Draw Title
    String title = slider.getName();
    g.setColour(Theme::mainText);
    g.setFont(fontSize);
    g.drawFittedText(title, 0, 0, width, fontSize * 2, Justification::centredBottom, 1, 1.f);

    // Draw BG Path
    g.setColour(Theme::bgComponent);
    g.fillRect(centreX, topDisplacement, barWidth, fheight - botDisplacement - topDisplacement);

    // Draw Active Path
    g.setColour(Theme::compFace);
    Path p;
    const float pointerLength = fheight - botDisplacement/2 - topDisplacement - ((fheight - botDisplacement/2 - topDisplacement) * (sliderPos / maxSliderPos));
    const float pointerThickness = barWidth;
    p.addRectangle(centreX, fheight - botDisplacement, pointerThickness, -pointerLength);
    g.fillPath(p);

    // Draw Thumb
    g.setColour(Theme::compHighlight);
    g.fillRect(centreX-1.f, fheight - pointerLength - botDisplacement - 2.f, pointerThickness+2.f, 4.f);
}

void ZxLookAndFeel::drawToggleButton(Graphics& g, ToggleButton& button, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
    const float margins = 5.f;

    const float height = fontSize * 2;
    const float width = button.getWidth() - margins * 2;

    const float x = 0.f + margins;
    const float y = button.getHeight() / 2 - height / 2;

    bool state = button.getToggleState();
    auto toggledOnBGColour = Theme::compFace;
    auto toggledOffBGColour = Theme::compHighlight;

    auto toggledOnTextColour = Theme::mainText;
    auto toggledOffTextColour = Theme::invertedText;

    g.setColour(shouldDrawButtonAsDown ? Colours::darkgrey : state ? toggledOnBGColour : toggledOffBGColour);
    g.fillRoundedRectangle(x, y, width, height, height / 2.f);

    g.setColour(state ? toggledOnTextColour : toggledOffTextColour);
    g.drawFittedText(button.getButtonText(), x, y, width, height, Justification::centred, 1);
}

void ZxLookAndFeel::drawButtonBackground(Graphics& g, Button& button, const Colour& backgroundColour, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
    const float margins = 5.f;

    const float width = button.getWidth() - margins * 2;
    const float height = fontSize * 2;

    const float x = 0.f + margins;
    const float y = button.getHeight()/2 - height/2;

    g.setColour(shouldDrawButtonAsDown? Colours::darkgrey : Theme::compFace);
    g.fillRoundedRectangle(x, y, width, height, height / 2.f);
}