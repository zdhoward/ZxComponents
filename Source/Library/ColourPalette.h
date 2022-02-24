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
}