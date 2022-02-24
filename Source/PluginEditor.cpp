/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"



//==============================================================================
ZxComponentsAudioProcessorEditor::ZxComponentsAudioProcessorEditor (ZxComponentsAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setLookAndFeel(&lnf);

    addAndMakeVisible(knobGroup);
    knobGroup.setTitle("Knob Group");

    addAndMakeVisible(knob1);
    knob1.setName("Knob 1");
    knob1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    knob1.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 20);
    
    addAndMakeVisible(knob2);
    knob2.setName("Knob 2");
    knob2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    knob2.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 20);
    
    addAndMakeVisible(knob3);
    knob3.setName("Knob 3");
    knob3.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    knob3.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 20);

    addAndMakeVisible(slider1);
    slider1.setName("Slider 1");
    slider1.setSliderStyle(Slider::LinearVertical);
    slider1.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 20);

    addAndMakeVisible(slider2);
    slider2.setName("Slider 2");
    slider2.setSliderStyle(Slider::LinearVertical);
    slider2.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 20);

    addAndMakeVisible(slider3);
    slider3.setName("Slider 3");
    slider3.setSliderStyle(Slider::LinearVertical);
    slider3.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 20);

    addAndMakeVisible(textButton);
    textButton.setButtonText("Text Button");

    addAndMakeVisible(toggleButton);
    toggleButton.setButtonText("Toggle Button");

    addAndMakeVisible(label);
    label.setText("Label: ", NotificationType::dontSendNotification);

    addAndMakeVisible(comboBox);
    auto list = StringArray{
        "ONE",
        "TWO",
        "THREE",
    };

    comboBox.addItemList(list, 1);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 500);
}

ZxComponentsAudioProcessorEditor::~ZxComponentsAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}

//==============================================================================
void ZxComponentsAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    //g.setColour (juce::Colours::white);
    //g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);

    g.setColour(ZxLookAndFeel::getBGColour());
    g.fillAll();
}

void ZxComponentsAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    //knob1.setBoundsRelative(0.15, 0.2, 0.3, 0.3);
    //knob2.setBoundsRelative(0.35, 0.2, 0.3, 0.3);
    //knob3.setBoundsRelative(0.55, 0.2, 0.3, 0.3);

    auto bounds = getLocalBounds();
    //bounds = bounds.removeFromTop(100);

    auto groupBounds = bounds.removeFromTop(120);
    knobGroup.setBounds(groupBounds);
    groupBounds.removeFromTop(10);
    groupBounds.removeFromBottom(10);

    knob1.setBounds(groupBounds.removeFromLeft(groupBounds.getWidth() * 0.33));
    knob2.setBounds(groupBounds.removeFromLeft(groupBounds.getWidth() * 0.5));
    knob3.setBounds(groupBounds.removeFromLeft(groupBounds.getWidth()));

    auto sliderBounds = bounds.removeFromTop(200);

    slider1.setBounds(sliderBounds.removeFromLeft(sliderBounds.getWidth() * 0.33));
    slider2.setBounds(sliderBounds.removeFromLeft(sliderBounds.getWidth() * 0.5));
    slider3.setBounds(sliderBounds.removeFromLeft(sliderBounds.getWidth()));

    auto buttonBounds = bounds.removeFromTop(100);
    textButton.setBounds(buttonBounds.removeFromLeft(buttonBounds.getWidth() * 0.5));
    toggleButton.setBounds(buttonBounds.removeFromLeft(buttonBounds.getWidth()));

    auto miscBounds = bounds.removeFromTop(100);
    label.setBounds(miscBounds.removeFromLeft(miscBounds.getWidth() * 0.5));
    comboBox.setBounds(miscBounds.removeFromLeft(miscBounds.getWidth()));
}
