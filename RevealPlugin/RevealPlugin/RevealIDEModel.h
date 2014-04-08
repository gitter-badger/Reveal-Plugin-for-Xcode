//
//  RevealIDEModel.h
//  RevealPlugin
//
//  Created by shjborage on 4/4/14.
//  Copyright (c) 2014 Saick. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDEConsoleTextView;

@interface DBGLLDBLauncher : NSObject

- (void)_executeLLDBCommands:(id)arg1;

@end

@interface DBGDebugSession : NSObject

@property (readonly) DBGLLDBLauncher *launcher;

- (void)requestPause;
- (void)requestContinue;

@end

@interface DBGDebugSessionController : NSObject

@property (readonly) DBGDebugSession *debugSession;

@end


@interface IDENavigatorArea : NSObject

@property NSArrayController *extensionsController;
- (id)currentNavigator;

@end


@interface IDEWorkspaceTabController : NSObject

@property (readonly) IDENavigatorArea *navigatorArea;
@property(readonly) IDEWorkspaceTabController *structureEditWorkspaceTabController;

@end


@interface IDEWorkspaceWindowController : NSObject

@property (readonly) IDEWorkspaceTabController *activeWorkspaceTabController;
@property (readonly) DBGDebugSessionController *debugSessionController;

@end

#pragma mark - Reveal IDE Tools

@interface RevealIDEModel : NSObject

+ (IDEWorkspaceTabController *)workspaceControllerIn;

+ (DBGDebugSession *)debugSessionIn;

+ (IDEConsoleTextView *)whenXcodeConsoleIn;

@end