//
//  PAZNAspects.h
//  PAZNAspects - A delightful, simple library for aspect oriented programming.
//
//  Copyright (c) 2014 Peter Steinberger. Licensed under the MIT license.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, PAZNAspectOptions) {
    PAZNAspectPositionAfter   = 0,            /// Called after the original implementation (default)
    PAZNAspectPositionInstead = 1,            /// Will replace the original implementation.
    PAZNAspectPositionBefore  = 2,            /// Called before the original implementation.
    
    PAZNAspectOptionAutomaticRemoval = 1 << 3 /// Will remove the hook after the first execution.
};

/// Opaque PAZNAspect Token that allows to deregister the hook.
@protocol PAZNAspectToken <NSObject>

/// Deregisters an aspect.
/// @return YES if deregistration is successful, otherwise NO.
- (BOOL)remove;

@end

/// The PAZNAspectInfo protocol is the first parameter of our block syntax.
@protocol PAZNAspectInfo <NSObject>

/// The instance that is currently hooked.
- (id)instance;

/// The original invocation of the hooked method.
- (NSInvocation *)originalInvocation;

/// All method arguments, boxed. This is lazily evaluated.
- (NSArray *)arguments;

@end

/**
 PAZNAspects uses Objective-C message forwarding to hook into messages. This will create some overhead. Don't add aspects to methods that are called a lot. PAZNAspects is meant for view/controller code that is not called a 1000 times per second.

 Adding aspects returns an opaque token which can be used to deregister again. All calls are thread safe.
 */
@interface NSObject (PAZNAspects)

/// Adds a block of code before/instead/after the current `selector` for a specific class.
///
/// @param block PAZNAspects replicates the type signature of the method being hooked.
/// The first parameter will be `id<PAZNAspectInfo>`, followed by all parameters of the method.
/// These parameters are optional and will be filled to match the block signature.
/// You can even use an empty block, or one that simple gets `id<PAZNAspectInfo>`.
///
/// @note Hooking static methods is not supported.
/// @return A token which allows to later deregister the aspect.
+ (id<PAZNAspectToken>)paznAspect_hookSelector:(SEL)selector
                                   withOptions:(PAZNAspectOptions)options
                                    usingBlock:(id)block
                                         error:(NSError **)error;

/// Adds a block of code before/instead/after the current `selector` for a specific instance.
- (id<PAZNAspectToken>)paznAspect_hookSelector:(SEL)selector
                                   withOptions:(PAZNAspectOptions)options
                                    usingBlock:(id)block
                                         error:(NSError **)error;

@end


typedef NS_ENUM(NSUInteger, PAZNAspectErrorCode) {
    PAZNAspectErrorSelectorBlacklisted,                   /// Selectors like release, retain, autorelease are blacklisted.
    PAZNAspectErrorDoesNotRespondToSelector,              /// Selector could not be found.
    PAZNAspectErrorSelectorDeallocPosition,               /// When hooking dealloc, only PAZNAspectPositionBefore is allowed.
    PAZNAspectErrorSelectorAlreadyHookedInClassHierarchy, /// Statically hooking the same method in subclasses is not allowed.
    PAZNAspectErrorFailedToAllocateClassPair,             /// The runtime failed creating a class pair.
    PAZNAspectErrorMissingBlockSignature,                 /// The block misses compile time signature info and can't be called.
    PAZNAspectErrorIncompatibleBlockSignature,            /// The block signature does not match the method or is too large.

    PAZNAspectErrorRemoveObjectAlreadyDeallocated = 100   /// (for removing) The object hooked is already deallocated.
};

extern NSString *const PAZNAspectErrorDomain;
