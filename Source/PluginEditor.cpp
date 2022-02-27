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
    //LookAndFeel::setDefaultLookAndFeel(&lnf);
    setLookAndFeel(&lnf);

    addAndMakeVisible(knobGroup);
    knobGroup.setTitle("Knob Group");

    addAndMakeVisible(knob1);
    knob1.setName("Knob 1");
    knob1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    knob1.setTextValueSuffix("Hz");
    
    addAndMakeVisible(knob2);
    knob2.setName("Knob 2");
    knob2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    
    addAndMakeVisible(knob3);
    knob3.setName("Knob 3");
    knob3.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);

    addAndMakeVisible(slider1);
    slider1.setName("Slider 1");
    slider1.setSliderStyle(Slider::LinearVertical);

    addAndMakeVisible(slider2);
    slider2.setName("Slider 2");
    slider2.setSliderStyle(Slider::LinearVertical);

    addAndMakeVisible(slider3);
    slider3.setName("Slider 3");
    slider3.setSliderStyle(Slider::LinearVertical);

    addAndMakeVisible(textButton);
    textButton.setButtonText("Text Button");

    addAndMakeVisible(toggleButton);
    toggleButton.setButtonText("Toggle Button");

    addAndMakeVisible(label);
    Font fontTitle = lnf.getTitleFont();
    fontTitle.setTypefaceName("Blackgrounds-Regular");
    fontTitle.setHeight(100.f);
    label.setFont(fontTitle);
    label.setText("ZxTools", NotificationType::dontSendNotification);
    label.setJustificationType(Justification::centred);
    label.setColour(label.textColourId, ZxLookAndFeel::getTitleColour());

    addAndMakeVisible(comboBox);
    auto list = StringArray{
        "ONE",
        "TWO",
        "THREE",
    };
    comboBox.addItemList(list, 1);
    comboBox.setName("- Presets -");

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 550);
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

    auto bounds = getLocalBounds();

    auto titleBounds = bounds.removeFromTop(100);
    label.setBounds(titleBounds.removeFromLeft(titleBounds.getWidth()));

    auto groupBounds = bounds.removeFromTop(150);
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

    auto buttonBounds = bounds.removeFromTop(50);
    textButton.setBounds(buttonBounds.removeFromLeft(buttonBounds.getWidth() * 0.5));
    toggleButton.setBounds(buttonBounds.removeFromLeft(buttonBounds.getWidth()));

    auto miscBounds = bounds.removeFromTop(30);
    miscBounds.removeFromLeft(miscBounds.getWidth() * 0.3333);
    comboBox.setBounds(miscBounds.removeFromLeft(miscBounds.getWidth() * 0.5));
}
