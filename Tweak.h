#import "RNCryptor/RNEncryptor.h"
#import "RNCryptor/RNDecryptor.h"
#import <JavaScriptCore/JavaScriptCore.h>
#import <CommonCrypto/CommonCrypto.h>

#define DEFAULTPROFILE @"Public Default::0dc9820f1ab911688e9432c05c6b9dpublic::#ffa500"
#define ENCPREFIX @"EC:\n"

#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

const RNCryptorSettings kEggCryptSettings = {
    .algorithm = kCCAlgorithmAES128,
    .blockSize = kCCBlockSizeAES128,
    .IVSize = kCCBlockSizeAES128,
    .options = kCCOptionPKCS7Padding,
    .HMACAlgorithm = kCCHmacAlgSHA256,
    .HMACLength = CC_SHA256_DIGEST_LENGTH,

    .keySettings = {
        .keySize = kCCKeySizeAES128,
        .saltSize = 8,
        .PBKDFAlgorithm = kCCPBKDF2,
        .PRF = kCCPRFHmacAlgSHA1,
        .rounds = 8000
    },

    .HMACKeySettings = {
        .keySize = kCCKeySizeAES128,
        .saltSize = 8,
        .PBKDFAlgorithm = kCCPBKDF2,
        .PRF = kCCPRFHmacAlgSHA1,
        .rounds = 8000
    }
};

@interface RCTUIManager
-(id)viewRegistry;
@end

@interface DCDThemeColor
+(id)TEXT_NORMAL;
@end

@interface RCTView : UIView
-(void)ECProfile;
-(void)ECNewProfile;
@end

@interface RCTImageSource
-(NSURLRequest *)request;
@end

@interface RCTImageView : UIView
-(NSArray<RCTImageSource*>*)imageSources;
@end

NSMutableDictionary *keys;
NSString *currentKey = nil;
UITextView *textView;
UIColor *currentTextColor;
JSContext *evalCtx;
NSString *profilesPath;
NSCache *encryptedCache;