/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Library/ZxLookAndFeel.h"

//==============================================================================
/**
*/
class ZxComponentsAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    ZxComponentsAudioProcessorEditor (ZxComponentsAudioProcessor&);
    ~ZxComponentsAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ZxComponentsAudioProcessor& audioProcessor;

    ZxLookAndFeel lnf;

    GroupComponent knobGroup;

    Slider knob1;
    Slider knob2;
    Slider knob3;

    Slider slider1;
    Slider slider2;
    Slider slider3;

    TextButton textButton;
    ToggleButton toggleButton;

    Label label;

    ComboBox comboBox;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ZxComponentsAudioProcessorEditor)
};
