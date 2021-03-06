//
//  MacSVGPluginCallbacks.h
//  macSVG
//
//  Created by Douglas Ward on 3/8/12.
//  Copyright © 2016 ArkPhone LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DOMElement;

@interface MacSVGPluginCallbacks : NSObject
{
}
@property (strong)id macSVGDocument;

//- (void)setMacSVGDocumentObject:(id)aMacSVGDocument;

@property (readonly, strong) id svgXmlDocument;                           // returns NSXMLDocument
@property (readonly, strong) id macSVGDocumentWindowController;      // returns MacSVGDocumentWindowController
@property (readonly, strong) id svgWebKitController;                      // returns SVGWebKitController
@property (readonly, strong) id svgWebView;                               // returns SVGWebView
@property (readonly) CGFloat zoomFactor;
@property (readonly, strong) id svgPathEditorSelectedPathElement;           // returns NSXMLElement
- (void)svgPathEditorSetSelectedPathElement:(NSXMLElement *)aSelectedPathElement;
@property (readonly, strong) id mouseEventsControllerActiveDOMElement;    // returns DOMElement
@property (copy) NSMutableArray *pathSegmentsArray;          // array of dictionaries for path segments
- (NSMutableArray *)buildPathSegmentsArrayWithPathString:(NSString *)pathString;
- (void)updatePathSegmentsAbsoluteValues:(NSMutableArray *)aPathSegmentsArray;
- (NSPoint)endPointForSegmentIndex:(NSInteger)segmentIndex
        pathSegmentsArray:(NSArray *)aPathSegmentsArray;
- (void)beginPluginEditorToolMode;
- (void)reloadAllViews;
- (void)updateSelections;                       // redraw selection rectangles and handles
- (void)updateActivePathInDOM;
- (void)updateSelectedPathInDOM;
- (void)updatePathInDOMForElement:(DOMElement *)pathElement pathSegmentsArray:(NSArray *)aPathSegmentsArray;
- (void)assignElementIDIfUnassigned:(NSXMLNode *)aNode;
- (NSString *)uniqueIDForElementTagName:(NSString *)elementTagName pendingIDs:(NSArray *)pendingIDs;
@property (readonly, copy) NSString *newMacsvgid;
- (void)pushUndoRedoDocumentChanges;

@property (readonly, copy) NSMutableArray *selectedElementsArray;
- (void)setToolMode:(NSInteger)newToolMode;
- (void)selectXMLElement:(NSXMLElement *)aXMLElement;
- (void)setActiveXMLElement:(NSXMLElement *)aXMLElement;
- (void)updateDOMSelectionRectsAndHandles;

@property (copy) NSString *selectedPathMode;

// elliptical arc parameters
@property  BOOL useRelativePathCoordinates;
    
@property  BOOL closePathAutomatically;

@property  BOOL curveSegmentContinuity;

@property (copy) NSString *largeArcFlagString;

@property (copy) NSString *sweepFlagString;

@property (copy) NSString *xAxisRotationString;

@property (copy) NSString *pathRadiusXString;

@property (copy) NSString *pathRadiusYString;

@property (copy) NSMutableDictionary *imageDictionary;

- (void)restartLastPathSegment;

- (NSString *)addCSSStyleName:(NSString *)styleName styleValue:(NSString *)styleValue toXMLElement:(NSXMLElement *)targetElement;
- (NSString *)addCSSStyleName:(NSString *)styleName styleValue:(NSString *)styleValue toDOMElement:(DOMElement *)targetElement;

- (NSMutableArray *)convertToAbsoluteCoordinates:(NSXMLElement *)pathElement;
- (NSMutableArray *)convertCurvesToAbsoluteCubicBezier:(NSXMLElement *)pathElement;
- (NSMutableArray *)convertCurvesToAbsoluteCubicBezierWithPathSegmentsArray:(NSMutableArray *)pathSegmentsArray;
- (NSMutableArray *)convertPathToAbsoluteCubicBezier:(NSXMLElement *)pathElement;
- (NSMutableArray *)convertPathToAbsoluteCubicBezierWithPathSegmentsArray:(NSMutableArray *)pathSegmentsArray;
- (NSMutableArray *)reversePathWithPathSegmentsArray:(NSMutableArray *)pathSegmentsArray;
- (NSMutableArray *)mirrorPathHorizontallyWithPathSegmentsArray:(NSMutableArray *)pathSegmentsArray;
- (NSMutableArray *)mirrorPathVerticallyWithPathSegmentsArray:(NSMutableArray *)pathSegmentsArray;
- (NSMutableArray *)flipPathHorizontallyWithPathSegmentsArray:(NSMutableArray *)pathSegmentsArray;
- (NSMutableArray *)flipPathVerticallyWithPathSegmentsArray:(NSMutableArray *)pathSegmentsArray;
- (NSMutableArray *)translatePathCoordinatesWithPathSegmentsArray:(NSMutableArray *)pathSegmentsArray x:(CGFloat)translateX y:(CGFloat)translateY;
- (NSMutableArray *)scalePathCoordinatesWithPathSegmentsArray:(NSMutableArray *)pathSegmentsArray scaleX:(CGFloat)scaleX scaleY:(CGFloat)scaleY;
- (NSMutableArray *)rotatePathCoordinatesWithPathSegmentsArray:(NSMutableArray *)pathSegmentsArray x:(CGFloat)rotateX y:(CGFloat)rotateY degrees:(CGFloat)degrees;
- (NSDictionary *) convertArcToEndPointWithRotation:(CGFloat)rotation angleStart:(CGFloat)angleStart angleExtent:(CGFloat)angleExtent
        cx:(CGFloat)cx cy:(CGFloat)cy rx:(CGFloat)rx ry:(CGFloat)ry;
- (NSDictionary *) convertArcToCenterPointWithStart:(CGPoint)start end:(CGPoint)end rx:(CGFloat)rx ry:(CGFloat)ry
        rotation:(CGFloat)rotation isLarge:(BOOL)isLarge isCounterClockwise:(BOOL)isCounterClockwise;

@end

