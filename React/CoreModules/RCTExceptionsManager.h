/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>
#import <React/RCTBridgeModule.h>
#import <react/renderer/mapbuffer/MapBuffer.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RCTExceptionsManagerDelegate <NSObject>

- (void)handleSoftJSExceptionWithMessage:(nullable NSString *)message
                                   stack:(nullable NSArray *)stack
                             exceptionId:(NSNumber *)exceptionId
                         extraDataAsJSON:(nullable NSString *)extraDataAsJSON;
- (void)handleFatalJSExceptionWithMessage:(nullable NSString *)message
                                    stack:(nullable NSArray *)stack
                              exceptionId:(NSNumber *)exceptionId
                          extraDataAsJSON:(nullable NSString *)extraDataAsJSON;

@optional
- (void)updateJSExceptionWithMessage:(nullable NSString *)message
                               stack:(nullable NSArray *)stack
                         exceptionId:(NSNumber *)exceptionId;

@end

@interface RCTExceptionsManager : NSObject <RCTBridgeModule>

- (instancetype)initWithDelegate:(id<RCTExceptionsManagerDelegate>)delegate;

- (void)reportSoftException:(nullable NSString *)message
                      stack:(nullable NSArray<NSDictionary *> *)stack
                exceptionId:(double)exceptionId;
- (void)reportFatalException:(nullable NSString *)message
                       stack:(nullable NSArray<NSDictionary *> *)stack
                 exceptionId:(double)exceptionId;
- (void)reportJsException:(const facebook::react::MapBuffer &)errorMap;

@property (nonatomic, weak) id<RCTExceptionsManagerDelegate> delegate;

@property (nonatomic, assign) NSUInteger maxReloadAttempts;

@end

NS_ASSUME_NONNULL_END
