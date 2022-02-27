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
    static Colour getPluginNameColour();
    static Colour getTitleColour();

    Font getTitleFont();

    void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
        float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override;

    void drawLinearSlider(Graphics& g, int x, int y, int width, int height, 
        float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle, Slider&) override;

    void drawGroupComponentOutline(Graphics& g, int w, int h, const String& text, const Justification&, GroupComponent&) override;

    void drawToggleButton(Graphics& g, ToggleButton& button, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;

    void drawButtonBackground(Graphics& g, Button& button, const Colour &backgroundColour, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;

    void drawButtonText(Graphics& g, TextButton& button, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override {};

    void drawComboBox(Graphics& g, int width, int height, bool isButtonDown, int buttonX, int buttonY, int buttonW, int buttonH, ComboBox& comboBox) override;

    void drawPopupMenuItem(Graphics& g, const Rectangle< int >& area, bool isSeparator, bool isActive, bool isHighlighted, bool isTicked, bool hasSubMenu, const String& text, const String& shortcutKeyText, const Drawable* icon, const Colour* textColour) override;

    void getIdealPopupMenuItemSize(const String& text, bool isSeparator, int standardMenuItemHeight, int& idealWidth, int& idealHeight) override;

    void drawPopupMenuBackground(Graphics& g, int width, int height) override;

    Typeface::Ptr fontBlackgrounds;
    Typeface::Ptr fontUbuntuRegular;
    Typeface::Ptr fontUbuntuBold;
    Typeface::Ptr fontUbuntuItalic;

    Font fontRegular;
    Font fontBold;
    Font fontItalic;
    Font fontTitle;

    String getDisplayValue(double val, String suffix = "", int precision = 2)
    {
        String valStr = "";
        bool addk = false;
        
        if (val > 999.f)
        {
            addk = true;
            val /= 1000.f;
        }

        double precisionMult = std::pow(10.0, precision);
        double vdouble = val * precisionMult;
        int vint = vdouble;
        vdouble = vint / precisionMult;

        valStr << String(vdouble);
        if (suffix != "" && suffix != "%")
            valStr << " ";

        if (addk)
            valStr << "k";

        valStr << suffix;

        return valStr;
    }
};

//struct ZxSlider : Slider
//{
//    ZxSlider()
//    {
//        setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 60, 20);
//    };
//
//    void valueChanged() override
//    {
//        setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 60, 20);        
//    };
//
//    void mouseExit(const MouseEvent &e) override
//    {
//        setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 60, 20);
//    }
//
//    void mouseDown(const MouseEvent& e) override
//    {
//        DBG("MOUSE RIGHT CLICKED");
//        ModifierKeys modifiers = ModifierKeys::getCurrentModifiersRealtime();
//
//        if (modifiers.isRightButtonDown())
//        {
//            setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 60, 20);            
//        }
//        else
//        {
//            Slider::mouseDown(e);
//            setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 60, 20);
//        }
//    };
//
//
//};

//bool Component::hitTest(int x, int y) {
//    Colour pixelColour = m_Image.getPixelAt(x, y);
//
//    if (pixelColour.isTransparent())
//        return false;
//
//    return true;
//};