/*
  ==============================================================================

    ColourPalette.h
    Created: 23 Feb 2022 10:52:09am
    Author:  ZECHS

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

using namespace juce;

namespace ColourPalette
{
    namespace Default
    {
        // A Bland Generic Black & White Palette
        //========================================================
        static Colour bgMain = Colours::black;
        static Colour bgGroup = Colours::darkgrey;
        static Colour bgComponent = Colours::grey;

        static Colour compFace = Colours::lightgrey;
        static Colour compHighlight = Colours::white;

        static Colour mainText = Colours::white;
        static Colour invertedText = Colours::black;
        static Colour altText = Colours::dimgrey;
        static Colour titleText = Colours::lightslategrey;
    }

    namespace Disabled
    {
        // A Palette for disabled items
        //========================================================
        static Colour bgMain = Colours::black;
        static Colour bgGroup = Colours::darkgrey;
        static Colour bgComponent = Colours::grey;

        static Colour compFace = Colours::lightgrey;
        static Colour compHighlight = Colours::white;

        static Colour mainText = Colours::white;
        static Colour invertedText = Colours::black;
        static Colour altText = Colours::dimgrey;
        static Colour titleText = Colours::lightslategrey;
    }

    namespace Oil
    {
        // https://lospec.com/palette-list/oil-6
        //========================================================
        static Colour bgMain = Colour(0xff494d7e);
        static Colour bgGroup = Colour(0xff272744).darker();
        static Colour bgComponent = Colour(0xff272744);

        static Colour compFace = Colour(0xff8b6d9c);
        static Colour compHighlight = Colour(0xfff2d3ab);

        static Colour mainText = Colour(0xfffbf5ef);
        static Colour invertedText = Colour(0xff272744);
        static Colour altText = Colour(0xfff2d3ab);
        static Colour titleText = Colour(0xfffbf5ef);
    }

    namespace InkPink
    {
        // https://lospec.com/palette-list/inkpink
        //========================================================
        static Colour bgMain = Colour(0xff260d34);
        static Colour bgGroup = bgMain.darker();//Colour(0xff272744).darker();
        static Colour bgComponent = Colour(0xff452459);

        static Colour compFace = Colour(0xff87286a);
        static Colour compHighlight = Colour(0xffd03791);

        static Colour mainText = Colour(0xffffffff);
        static Colour invertedText = Colour(0xff260d34);
        static Colour altText = Colour(0xffd03791);
        static Colour titleText = Colour(0xffffffff);
    }

    namespace Curiosities
    {
        // https://lospec.com/palette-list/curiosities
        //========================================================
        static Colour bgMain = Colour(0xffffeecc);
        static Colour bgGroup = Colour(0xffffb0a3);
        static Colour bgComponent = Colour(0xff15788c);

        static Colour compFace = Colour(0xff00b9be);
        static Colour compHighlight = Colour(0xffff6973);

        static Colour mainText = Colour(0xff46425e);
        static Colour invertedText = Colour(0xffffeecc);
        static Colour altText = Colour(0xffff6973);
        static Colour titleText = Colour(0xffff6973);
    }

    namespace LemonLime
    {
        // https://lospec.com/palette-list/green-top-down
        //========================================================
        static Colour bgMain = Colour(0xff267049);
        static Colour bgGroup = Colour(0xff28594f);
        static Colour bgComponent = Colour(0xff72b046);

        static Colour compFace = Colour(0xff9fd943);
        static Colour compHighlight = Colour(0xfff0fa37);

        static Colour mainText = Colour(0xfff0fa37);
        static Colour invertedText = Colour(0xff28594f);
        static Colour altText = Colour(0xff9fd943);
        static Colour titleText = Colour(0xfff0fa37);
    }

    namespace Yamazaki
    {
        // https://lospec.com/palette-list/yamazaki
        //========================================================
        static Colour bgMain = Colour(0xff363a54);
        static Colour bgGroup = Colour(0xff843451);
        static Colour bgComponent = Colour(0xff8c7e7d);

        static Colour compFace = Colour(0xffc74061);
        static Colour compHighlight = Colour(0xffd699a0);

        static Colour mainText = Colour(0xffd9c8be);
        static Colour invertedText = Colour(0xff363a54);
        static Colour altText = Colour(0xffc74061);
        static Colour titleText = Colour(0xffd9c8be);
    }

    namespace IcyWitch
    {
        // https://lospec.com/palette-list/icywitch
        //========================================================
        static Colour bgMain = Colour(0xff32535f);
        static Colour bgGroup = Colour(0xff313638);
        static Colour bgComponent = Colour(0xff0a777a);

        static Colour compFace = Colour(0xff4aa881);
        static Colour compHighlight = Colour(0xff73efe8);

        static Colour mainText = Colour(0xffecf3b0);
        static Colour invertedText = Colour(0xff313638);
        static Colour altText = Colour(0xff4aa881);
        static Colour titleText = Colour(0xffecf3b0);
    }

    namespace DontForget
    {
        // https://lospec.com/palette-list/dnot-froget
        //========================================================
        static Colour bgMain = Colour(0xff6f4367);
        static Colour bgGroup = Colour(0xff253657);
        static Colour bgComponent = Colour(0xffa69aca);

        static Colour compFace = Colour(0xfff5a1a1);
        static Colour compHighlight = Colour(0xffe76d8a);

        static Colour mainText = Colour(0xfff8e9e5);
        static Colour invertedText = Colour(0xff253657);
        static Colour altText = Colour(0xffe76d8a);
        static Colour titleText = Colour(0xfff8e9e5);
    }

    namespace Puffball
    {
        // https://lospec.com/palette-list/puffball-8
        //========================================================
        static Colour bgMain = Colour(0xff548b71);
        static Colour bgGroup = Colour(0xff5a473e);
        static Colour bgComponent = Colour(0xffe0bb68);

        static Colour compFace = Colour(0xffd58353);
        static Colour compHighlight = Colour(0xff97b34e);

        static Colour mainText = Colour(0xffeedbc8);
        static Colour invertedText = Colour(0xff5a473e);
        static Colour altText = Colour(0xff97b34e);
        static Colour titleText = Colour(0xffeedbc8);
    }

    namespace Violets
    {
        // https://lospec.com/palette-list/6-violets
        //========================================================
        static Colour bgMain = Colour(0xff2c2fa3);
        static Colour bgGroup = Colour(0xff2b0b76);
        static Colour bgComponent = Colour(0xff4792eb);

        static Colour compFace = Colour(0xff74d7e9);
        static Colour compHighlight = Colour(0xffb343d1);

        static Colour mainText = Colour(0xff74d7e9);
        static Colour invertedText = Colour(0xff2b0b76);
        static Colour altText = Colour(0xffb343d1);
        static Colour titleText = Colour(0xff74d7e9);
    }
}